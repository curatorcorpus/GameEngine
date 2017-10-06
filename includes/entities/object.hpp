#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <shader.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Object {

protected:

	std::string name;

	// homogenous coordinates
	glm::mat4 transform;
	glm::mat4 translation;
	glm::mat4 rotation;
	glm::mat4 scale;

	glm::mat4 update_transform();

public:

	Object();
	Object(std::string name);
	virtual ~Object();

	glm::mat4 get_transform();

	void set_transform(glm::mat4 transform);
	void set_translation(glm::mat4 translation);
	void set_rotation(glm::mat4 rotation);
	void set_scale(glm::mat4 scale);
};

#endif