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
	DisplayManager(std::string title, int width, int height);
	~DisplayManager();

	GLFWwindow* window;
};

#endif