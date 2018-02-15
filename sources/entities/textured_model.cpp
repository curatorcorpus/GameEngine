#include <textured_model.hpp>

TexturedModel::TexturedModel(std::string texture_name, std::string shader_name) : Model(shader_name) {

	this->texture_name = texture_name;
}

TexturedModel::~TexturedModel() {

}

bool TexturedModel::load_texture_image(std::string name) {

	std::string file_name = Texture_Path + name + PNG_Suffix;

	FILE *fp;

	// Try open the image file - read bytes.
	if((fp = fopen(file_name.c_str(), "rb")) == NULL) {
		return false;
	}

	fclose(fp);

	return true;
}

