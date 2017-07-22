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
#include <glm/glm.hpp>

class Shader {

protected:

	GLuint prog_id;
	GLuint mvp_id;
	GLuint m_id;
	GLuint v_id;

	GLuint      compile(std::string& file_name, const char* code);
	std::string open_file(std::string& shader_path);
	GLuint 		link_shaders(GLuint& vert_id, GLuint& frag_id);
	void        setup(std::string& vert, std::string& frag);

public:

	Shader(std::string shader_path);
	~Shader();

	void bind();
	void update_matrices(glm::mat4& m, glm::mat4& v, glm::mat4& mvp);
	void update_mvp(glm::mat4& mvp);
};


#endif