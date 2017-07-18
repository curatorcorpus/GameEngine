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

	GLuint prog_id;

	void        bind(GLuint& program);
	GLuint      compile(std::string& file_name, const char* code);
	std::string open_file(std::string& shader_path);
	GLuint 		link_shaders(GLuint& vert_id, GLuint& frag_id);
	void        setup(std::string& vert, std::string& frag);

public:

	Shader(std::string shader_path);
	~Shader();
};


#endif