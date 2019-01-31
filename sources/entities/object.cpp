#include <object.hpp>

Object::Object(std::string name, std::string texture_name) : Model()
{
	this->name = name;
	this->tex_info.name = texture_name;
}

Object::~Object() 
{	
	glDeleteTextures(1, &tex_info.id);
}

void Object::setup(ObjectShader* o_shader) 
{
	this->o_shader = o_shader;

	// load 3D file and assign geometry to this class instance.
 	Loader::load_obj(name, this);

	load_texture();
}

void Object::load_texture()
{
	glGenTextures(1, &tex_info.id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex_info.id);
   // std::cerr << "[DEBUG::TEXTURED_MODEL::TextureID] " << texture_id << std::endl; 
    // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Loader::load_PNG(&tex_info);
	if(tex_info.is_loaded) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_info.width, tex_info.height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_info.data);
        glGenerateMipmap(GL_TEXTURE_2D);
		std::cerr << "[DEBUG::OBJECT]" << " Texture " << tex_info.name << " loaded!" << std::endl;
	}
	else 
	{
		std::cerr << "[DEBUG::TERRAIN]" << " Texture " << tex_info.name << " failed to load!" << std::endl;
		return;
	}

	// Set uniform variable name for shader program.
   // std::cerr << "[DEBUG::TEXTURED_MODEL::SHADER_ID]" << shader->get_prog_id() << std::endl;
    
    GLuint shader_id = this->o_shader->get_prog_id();
    glUniform1i(glGetUniformLocation(shader_id, "_texture"), GL_TEXTURE0); // gets uniform location in shader to update texture values. 

    // unbind
    glBindTexture(GL_TEXTURE_2D, 0);

    // free texture in memory. 
    free(tex_info.data);
}

void Object::render(Camera* camera) 
{
	o_shader->bind(); // could be bound in master renderer for terrains.

    // activate binded texture.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->tex_info.id);

    // obtain current MVP and model transform.
	glm::mat4 model = this->transform;
	glm::mat4 mvp = camera->get_view_proj_mat() * model;

    // update MVP and camera pos in bound shader.
	o_shader->update_mvp(mvp);
	o_shader->update_cam_pos(camera->get_pos());

	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render();
	}

    glBindTexture(GL_TEXTURE_2D, 0);

	o_shader->unbind();
}

void Object::set_meshes() 
{
	for(int i = 0; i < meshes.size(); i++)
	{	
		std::cerr << "[OBJECT::SETUP_MESHES] " << this->o_shader->get_prog_id() << std::endl;
		meshes[i].setup();
	}
}