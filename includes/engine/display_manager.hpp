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
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class DisplayManager {

private:

	bool fullscrn;
	int width, height;

	std::string title;

	void setup_glfw();
	void setup_glew();
	void setup_opengl();

public:

	DisplayManager(std::string title, bool fullscrn, int width = 1280, int height = 1080);
	~DisplayManager();

	GLFWwindow* window;

	int get_height();
	int get_width();

	void set_dimensions(int width, int height);
};

#endif