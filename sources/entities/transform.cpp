#include <transform.hpp>

Transform::Transform() 
{
	this->translation = glm::translate(glm::mat4(), glm::vec3(0.0f));
	this->rotation 	  = glm::mat4(0.0f);
	this->scale 	  = glm::scale(glm::mat4(), glm::vec3(1.0f));
	
	this->transform = get_identity();
}

Transform::Transform(std::string name) 
{
	Transform();
}

Transform::~Transform() {}

glm::mat4 Transform::get_identity()
{
	return glm::mat4(1.0f);
}

glm::mat4 Transform::get_transform() 
{
	return transform;
}

glm::mat4 Transform::update_transform() 
{
	this->transform = scale * rotation * translation;
}

void Transform::set_transform(glm::mat4 transform) 
{	
	this->transform = transform;
	this->transform = update_transform();
}

void Transform::set_translation(glm::mat4 translation) 
{
	this->translation = translation;
	this->transform = update_transform();
}

void Transform::set_rotation(glm::mat4 rotation) 
{
	this->rotation = rotation;
	this->transform = update_transform();
}

void Transform::set_scale(glm::mat4 scale) 
{
	this->scale = scale;
	this->transform = update_transform();
}