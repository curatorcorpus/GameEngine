#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>

/*
	External Libraries.
*/
#include <GL/glew.h>

class Shader {

protected:
	GLuint prog_id;

public:

	Shader(std::string shader_path);
	~Shader();

	void   init_shader();
	GLuint load_shaders();
};


#endif