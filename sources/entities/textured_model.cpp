#include <textured_model.hpp>

TexturedModel::TexturedModel(std::string texture_name)
{
	this->texture_name = texture_name;
}

TexturedModel::~TexturedModel() 
{
   glDeleteTextures(1, &texture_id);
}

void TexturedModel::setup() 
{
	glGenTextures(1, &texture_id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);
   // std::cerr << "[DEBUG::TEXTURED_MODEL::TextureID] " << texture_id << std::endl; 
    // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	bool isLoaded = load_texture_image(texture_name);
	if(isLoaded) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->texture_image);
        glGenerateMipmap(GL_TEXTURE_2D);
		std::cerr << "[DEBUG::TEXTURED_MODEL]" << " Texture " << texture_name << " loaded!" << std::endl;
	}
	else 
	{
		std::cerr << "[DEBUG::TEXTURED_MODEL]" << " Texture " << texture_name << " failed to load!" << std::endl;
		return;
	}

	// Set uniform variable name for shader program.
   // std::cerr << "[DEBUG::TEXTURED_MODEL::SHADER_ID]" << shader->get_prog_id() << std::endl;
    GLint test = glGetUniformLocation(this->shader->get_prog_id(), "_texture");
    std::cerr << "[DEBUG::TEXTURED_MODEL::UNI_LOC] " << " " << test << std::endl;
    
    glUniform1i(test, GL_TEXTURE0);
}
void TexturedModel::set_size(int size)
{
    this->size = size;
    std::cout << "SIZE " << size << std::endl;
}
void TexturedModel::render(Camera* camera) 
{
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, texture_id);

	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render(camera);
	}
}