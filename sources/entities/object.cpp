#include <object.hpp>

Object::Object() {

	translation = glm::translate(glm::mat4(), glm::vec3(0.0f));
	rotation 	= glm::mat4(1.0f);
	scale 		= glm::scale(glm::mat4(),	  glm::vec3(1.0f));
	transform 	= translation * rotation * scale;

	shader = nullptr;
}

Object::Object(std::string name) {

	Object();
	this->name = name;
}

Object::~Object() {

}