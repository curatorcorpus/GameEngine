#include <skybox_shader.hpp>

/*

*/
SkyboxShader::SkyboxShader() : Shader()
{
    // relative local path to shader res.
    std::string vert_shader_path = "../resources/shaders/skybox_vert.glsl";
	std::string frag_shader_path = "../resources/shaders/skybox_frag.glsl";

    this->setup(vert_shader_path, frag_shader_path);
}

/*

*/
SkyboxShader::~SkyboxShader()
{
	glDeleteProgram(this->prog_id);
}

void SkyboxShader::setup(std::string& vert_path, std::string& frag_path)
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

void SkyboxShader::set_uniform_loc()
{
    // create reference to uniform variables inside prog_id shader program. 
	//this->mvp_id     = glGetUniformLocation(prog_id, "MVP");
	this->v_id       = glGetUniformLocation(prog_id, "V");
	this->p_id       = glGetUniformLocation(prog_id, "P");
	//this->cam_pos_id = glGetUniformLocation(prog_id, "cam_pos");
    this->tex_uniloc = glGetUniformLocation(prog_id, "cubemap");
}

GLuint SkyboxShader::get_texuniloc()
{
    return tex_uniloc;
}