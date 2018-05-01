#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

class Light {

private:

	glm::vec3 position;

public:

	Light(glm::vec3 position);
	~Light();

	glm::vec3 get_pos();

	void set_pos(glm::vec3 pos);
};

#endif