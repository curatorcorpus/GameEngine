#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

private:

	float fov;				// viewing angle at a given movement.
	float aspect_ratio; 	// defines ratio of the width and the height.
	float near_clip;		// defines closest distance to render.
	float far_clip;			// defines most furthest distance to render.
	float horizontal_angle; // 
	float vertical_angle;   // 

	glm::vec3 position;
	glm::vec3 lookat;
	glm::vec3 upwards;

	glm::mat4 view_matrix;
	glm::mat4 projection_matrix;

public:

	Camera();
	Camera(float fov, float aspect_ratio, float near, float far); // with camera intrinsic parameters.
	Camera(glm::mat4 view_matrix, glm::mat4 projection_matrix);
	~Camera();

	void set_pos();
	void set_lookat();
	void set_upwards();

	glm::mat4 get_view_mat();
	glm::mat4 get_proj_mat();
	glm::mat4 get_view_proj_mat();
};

#endif