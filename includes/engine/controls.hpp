#ifndef CONTROLS_HPP
#define CONTROLS_HPP

/*
	C++ Libraries
*/
#include <iostream>

/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>

#include <camera.hpp>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Controls {

private:

	Camera* camera;
	GLFWwindow* window;

	int width, height;

	float key_speed;
	float mouse_speed;
	float horizontal_angle;
	float vertical_angle;

public:
	Controls(Camera* camera, GLFWwindow* window);
	~Controls();

	void update();
};

#endif