#include <camera.hpp>

Camera::Camera() {

	position = glm::vec3(0.0f, 10.0f, 0.0f);
	lookat   = glm::vec3(0.0f, 1.0f, 0.0f);
	upwards  = glm::vec3(0.0f, 1.0f, 0.0f);

	fov 		 = 70.0f;
	aspect_ratio = 16.0f/9.0f;
	near_clip    = 0.1f;
	far_clip	 = 1000.0f;

	// requires pos, view direction, and up direction. 
	// generates transformation matrix for camera view space.
	// requires fov, aspect ratio, near and far clipping plane.
 	// generates transformation matirx for frustrum (clipping) space.
	view_matrix  	  = glm::lookAt(position, lookat, upwards); 
	projection_matrix = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
}

Camera::Camera(float fov, float aspect_ratio, float near, float far) {

	this->fov 		   = fov;
	this->aspect_ratio = aspect_ratio;
	this->near_clip    = near;
	this->far_clip     = far;

	Camera(); // default constructor called first, data fields overwritten.
}

Camera::Camera(glm::mat4 view_matrix, glm::mat4 projection_matrix) {

	Camera(); // default constructor called first, data fields overwritten.

	this->view_matrix 		= view_matrix;
	this->projection_matrix = projection_matrix;
}

Camera::~Camera() {}

float Camera::get_fov() {

	return fov;
}

glm::vec3 Camera::get_pos() {

	return position;
}

void Camera::set_fov(float fov) {

	this->fov = fov;
	projection_matrix = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
}

void Camera::set_pos(glm::vec3 pos) {

	this->position = pos;
	view_matrix = glm::lookAt(this->position, this->lookat, this->upwards);
}

void Camera::set_lookat(glm::vec3 pos, glm::vec3 lookat, glm::vec3 up) {

	this->position = pos;
	this->lookat = lookat;
	this->upwards = up;

	view_matrix = glm::lookAt(this->position, this->lookat, this->upwards);
}

glm::mat4 Camera::get_view_mat() {

	return view_matrix;
}

glm::mat4 Camera::get_proj_mat() {

	return projection_matrix;
}

glm::mat4 Camera::get_view_proj_mat() {

	return projection_matrix * view_matrix;
}