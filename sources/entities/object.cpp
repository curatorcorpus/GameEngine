#include <object.hpp>

Object::Object() {

	name = "object";

	translation = glm::translate(glm::mat4(), glm::vec3(0.0f));
	rotation 	= glm::mat4(1.0f);
	scale 		= glm::scale(glm::mat4(),	  glm::vec3(1.0f));
	transform 	= this->update_transform();
}

Object::Object(std::string name) {

	Object();
	this->name = name;
}

Object::~Object() {}

glm::mat4 Object::get_transform() {

	return transform;
}

glm::mat4 Object::update_transform() {

	this->transform = scale * rotation * translation;
}

void Object::set_transform(glm::mat4 transform) {
	
	this->transform = transform;
	this->transform = update_transform();
}

void Object::set_translation(glm::mat4 translation) {

	this->translation = translation;
	this->transform = update_transform();
}

void Object::set_rotation(glm::mat4 rotation) {

	this->rotation = rotation;
	this->transform = update_transform();
}

void Object::set_scale(glm::mat4 scale) {

	this->scale = scale;
	this->transform = update_transform();
}