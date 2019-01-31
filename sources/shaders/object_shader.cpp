#include <object_shader.hpp>

ObjectShader::ObjectShader() : Shader()
{
    // relative local path to shader res.
    std::string vert_shader_path = "../resources/shaders/object_vert.glsl";
	std::string frag_shader_path = "../resources/shaders/object_frag.glsl";

    this->setup(vert_shader_path, frag_shader_path);
}

ObjectShader::~ObjectShader() 
{
	glDeleteProgram(this->prog_id);
}

void ObjectShader::setup(std::string& vert_path, std::string& frag_path)
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

    // bind, maybe needed?
	bind_attrib_loc();
    
    // create reference to uniform variables inside prog_id shader program.
    set_uniform_loc();
}

void ObjectShader::set_uniform_loc()
{
    // create reference to uniform variables inside prog_id shader program. 
	this->mvp_id     = glGetUniformLocation(prog_id, "MVP");
	this->m_id       = glGetUniformLocation(prog_id, "M");
	this->v_id       = glGetUniformLocation(prog_id, "V");
	this->cam_pos_id = glGetUniformLocation(prog_id, "cam_pos");
    this->tex_uniloc = glGetUniformLocation(prog_id, "_texture");
}

GLuint ObjectShader::get_texuniloc()
{
    return tex_uniloc;
}