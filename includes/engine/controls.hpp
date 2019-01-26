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

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Controls* test = static_cast<Controls*>(glfwGetWindowUserPointer(window));
		test->key_callback(key, scancode, action, mods);
	}

public:
	Controls(Camera* camera, GLFWwindow* window);
	~Controls();

	// used more for an interrupt event.
	void key_callback(int key, int scancode, int action, int mods)
	{
		if(key == GLFW_KEY_F12 && action == GLFW_PRESS)
		{
			std::cerr << "[DEBUG::CONTROLS] Screenshot saved!" << std::endl;
		}
	}

	void update();
};

#endif