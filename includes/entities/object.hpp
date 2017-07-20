#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <shader.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/transformation_matrix.hpp>

class Object {

protected:

	Shader* shader;

	std::string name;

	glm::mat4 transform;
	glm::mat4 position;
	glm::mat4 rotation;
	glm::mat4 scale;

public:


};

#endif