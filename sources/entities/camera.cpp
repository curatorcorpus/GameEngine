#include <camera.hpp>

Camera::Camera() {

	fov 		 = 45.0f;
	aspect_ratio = 16.0f/9.0f;
	near_clip    = 0.1f;
	far_clip	 = 1000.0f;

	// requires pos, view direction, and up direction. 
	// generates transformation matrix for camera view space.
	view_matrix  	  = glm::lookAt(position, lookat, upwards); 

	// requires fov, aspect ratio, near and far clipping plane.
 	// generates transformation matirx for frustrum (clipping) space.
	projection_matrix = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
}

glm::mat4 Camera::get_view_mat() {
	return view_matrix;
}

glm::mat4 Camera::get_proj_mat() {
	return projection_matrix;
}

glm::mat4 Camera::get_view_proj_mat() {
	return view_matrix * projection_matrix;
}