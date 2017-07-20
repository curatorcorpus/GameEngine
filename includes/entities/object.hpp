#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <shader.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Object {

protected:

	Shader* shader;

	std::string name;

	// homogenous coordinates
	glm::mat4 transform;
	glm::mat4 translation;
	glm::mat4 rotation;
	glm::mat4 scale;

public:

	Object();
	Object(std::string name);
	~Object();

	void set_transform();
	void set_translation();
	void set_rotation();
	void set_scale();

	void set_shader();
};

#endif