#ifndef DISPLAY_HPP
#define DISPLAY_HPP

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

class Display {

private:

	bool fullscrn, vsync;
	int width, height;

	std::string title;

	void setup_glfw();
	void setup_glew();
	void setup_opengl();

	GLFWwindow* window;

public:

	Display(
			std::string title, 
			int width = 1280, 
			int height = 1080,
			bool fullscrn = false, 
			bool vsync = true
		);
	~Display();

	int get_height();
	int get_width();
	GLFWwindow* get_window();

	void set_dimensions(int width, int height);
};

#endif