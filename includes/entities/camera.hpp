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

	glm::vec3 position = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 lookat   = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 upwards  = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 view_matrix;
	glm::mat4 projection_matrix;

public:

	Camera();
	Camera(glm::mat4 view_matrix, glm::mat4 projection_matrix);
	~Camera();

};

#endif