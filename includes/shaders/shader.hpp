#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*
	External Libraries.
*/
#include <GL/glew.h>

class Shader {

protected:

	std::string vert_shader_path;
	std::string frag_shader_path;

	GLuint prog_id;

	void        bind(GLuint& program);
	GLuint      compile(std::string& file_name, const char* code);
	std::string open_file(std::string& shader_path);
	GLuint 		link_shaders(GLuint& vert_id, GLuint& frag_id);

public:

	Shader(std::string shader_path);
	~Shader();

	void setup();
};


#endif