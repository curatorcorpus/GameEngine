#include <shader.hpp>

/*
	Assumes shader names will be the same for both frag and vert shaders.
*/
Shader::Shader(std::string shader_name) 
{
	// relative local path to shader res.
	std::string loc_res_path  = "../resources/shaders/";
	std::string vertex_suffix = "_vert.glsl";
	std::string frag_suffix   = "_frag.glsl";
	std::string vert_shader_path = loc_res_path + shader_name + vertex_suffix;
	std::string frag_shader_path = loc_res_path + shader_name + frag_suffix;

	setup(vert_shader_path, frag_shader_path);
}

/*
	Method used to delete current shader program.
*/
Shader::~Shader()
{	
	glDeleteProgram(prog_id);
}

/*
	Method for compiling and creating reference to shaders.
*/
void Shader::setup(std::string& vert_path, std::string& frag_path) 
{
	// read in shader files.
	std::string vert_shader_code = open_file(vert_path);
	std::string frag_shader_code = open_file(frag_path);

	// compile shader programs.
	GLuint vert_id = compile(vert_path, vert_shader_code.c_str());
	GLuint frag_id = compile(frag_path, frag_shader_code.c_str());

	// compiled shaders to program
	this->prog_id = link_shaders(vert_id, frag_id);
	std::cerr << "[DEBUG::SHADER::PROG_ID] " << prog_id << std::endl;
	// bind 
	bind_attrib_loc();

	// create reference to uniform variables inside prog_id shader program. 
	this->mvp_id = glGetUniformLocation(prog_id, "MVP");
	this->m_id   = glGetUniformLocation(prog_id, "M");
	this->v_id   = glGetUniformLocation(prog_id, "V");

	this->cam_pos_id = glGetUniformLocation(prog_id, "cam_pos");
}

/*
	Method used to read in shader files. 
*/
std::string Shader::open_file(std::string& shader_path) 
{
	// read shader file code.
	std::string code = "";
	std::ifstream shader_stream(shader_path.c_str(), std::ios::in);
	if(shader_stream.is_open()) {
		std::string line = "";
		
		while(getline(shader_stream, line))
		{
			code += "\n" + line;
		}
		shader_stream.close();
	} 
	else 
	{
		std::cerr << "[DEBUG::SHADER] Shader Failed to load! Wrong path?" << std::endl;
	}

	return code;
}

/*

*/
void Shader::bind_attrib_loc() 
{
	glBindAttribLocation(prog_id, 0, "vertices");
	glBindAttribLocation(prog_id, 1, "normals");
	glBindAttribLocation(prog_id, 2, "uvs");
}

/*

*/
GLuint Shader::compile(std::string& file_name, const char* code) 
{
	std::cerr << "[DEBUG::SHADER] Compiling Shader: " << file_name << std::endl;

	bool is_vert_shader = true;

	// create empty shader object. [only limited to vert and frag shader]
	// determines which shader processor should be used for the provided code.
	GLuint shader_id;
	if(file_name.find("vert") != std::string::npos) 
	{
		shader_id = glCreateShader(GL_VERTEX_SHADER);
	} 
	else 
	{
		shader_id = glCreateShader(GL_FRAGMENT_SHADER);
		is_vert_shader = false;
	}

	glShaderSource(shader_id, 1, &code, NULL); // attach source code to empty shader object.
	glCompileShader(shader_id);				   // compile

	GLint result = GL_FALSE;
	GLint info_log_length;

	// check if shader programs compiled.
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_length);

	if(info_log_length > 0) 
	{
		std::vector<char> err_msg(info_log_length + 1);
		glGetShaderInfoLog(shader_id, info_log_length, NULL, &err_msg[0]);

		std::cerr << "[DEBUG::SHADER] " << &err_msg[0] << std::endl;
		std::cerr << "[DEBUG::SHADER] Shader Compilation Failed!" << std::endl;
	}

	if(is_vert_shader) 
	{
		std::cerr << "[DEBUG::SHADER] Vert Shader Compilation Succeed!" << std::endl;
	} 
	else 
	{
		std::cerr << "[DEBUG::SHADER] Frag Shader Compilation Succeed!" << std::endl;
	}

	return shader_id;
}

/*

*/
GLuint Shader::link_shaders(GLuint& vert_id, GLuint& frag_id) 
{
	std::cerr << "[DEBUG::SHADER] Linking shader program" << std::endl;

	// create program object.
	GLuint program = glCreateProgram();
	glAttachShader(program, vert_id);
	glAttachShader(program, frag_id);
	glLinkProgram(program);

	// check program is running
	GLint result = GL_FALSE;
	GLint info_log_length;

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);

	if(info_log_length > 0) 
	{
		std::vector<char> err_msg(info_log_length + 1);
		glGetProgramInfoLog(program, info_log_length, NULL, &err_msg[0]);

		std::cerr << "[DEBUG::SHADER] " << &err_msg[0] << std::endl;
		std::cerr << "[DEBUG::SHADER] Program Linking Failed!" << std::endl;
	}

	// detach shader object from program
	glDetachShader(program, vert_id);
	glDetachShader(program, frag_id);

	// free shader object memory.
	glDeleteShader(vert_id);
	glDeleteShader(vert_id);

	std::cerr << "[DEBUG::SHADER] Shaders Linked Successfully to Program!" << std::endl;

	return program;
}

void Shader::bind() 
{
	glUseProgram(this->prog_id);
}

void Shader::unbind() 
{
	glUseProgram(0);
}

void Shader::update_cam_pos(glm::vec3 position) {

	glUniform3f(cam_pos_id, position.x, position.y, position.z);
}

void Shader::update_matrices(glm::mat4& m, glm::mat4& v, glm::mat4& mvp) 
{
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, &mvp[0][0]);
	glUniformMatrix4fv(m_id,   1, GL_FALSE, &m[0][0]);
	glUniformMatrix4fv(v_id,   1, GL_FALSE, &v[0][0]);	
}

void Shader::update_mvp(glm::mat4& mvp) 
{
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, &mvp[0][0]);
}

GLuint Shader::get_prog_id() 
{
	return prog_id;
}