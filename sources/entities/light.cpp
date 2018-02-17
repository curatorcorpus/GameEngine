#include <light.hpp>

Light::Light(glm::vec3 position) {

	this->position = position;
}

Light::~Light() {

}

glm::vec3 Light::get_pos() {

	return position;
}

void Light::set_pos(glm::vec3 pos) {

	this->position = pos;
}