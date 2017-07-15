#ifndef DISPLAY_MANAGER_HPP
#define DISPLAY_MANAGER_HPP

/*
	C++ Libraries
*/
#include <iostream>

/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>

class DisplayManager {

private:

public:
	DisplayManager(std::string title, int width = 1280, int height = 1080);
	~DisplayManager();

	GLFWwindow* window; // doesnt allow for GLFWwindow to be used as method type. 
	//GLFWwindow* get_window();
};

#endif