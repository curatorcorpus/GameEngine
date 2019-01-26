#ifndef TEXTURED_MODEL_HPP
#define TEXTURED_MODEL_HPP

#include <memory.h>
#include <iostream>
#include <model.hpp>
#include <png.h>

#include <GL/glut.h>

class TexturedModel : public Model {

protected:
	const char* Texture_Path = "../resources/textures/";
	const char* PNG_Suffix 	 = ".png";

	uint width, height;

	std::string texture_name;

	GLubyte* texture_image;
	GLuint 	 texture_id;

		int size = 0;

public:
	TexturedModel(std::string texture_name);
	~TexturedModel();

	bool load_texture_image(std::string name);
	void setup();
	void set_size(int size);
	void render(Camera* camera);
};

#endif