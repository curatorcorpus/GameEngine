#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

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

class InputManager {

private:

	Camera* camera;
	GLFWwindow* window;

	float key_speed;
	float mouse_speed;
	float horizontal_angle;
	float vertical_angle;

public:
	InputManager(Camera* camera, GLFWwindow* window);
	~InputManager();

	void update();
};

#endif