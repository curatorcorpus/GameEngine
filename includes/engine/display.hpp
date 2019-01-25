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
	int cursor_focus_status;

	std::string title;

	void setup_glfw();
	void setup_glew();
	void setup_opengl();

	GLFWwindow* window;

	static void cursor_enter_callback(GLFWwindow* window, int entered)
	{
		Display* test = static_cast<Display*>(glfwGetWindowUserPointer(window));
		test->cursor_enter_callback(entered);
	}

public:

	Display(
			std::string title, 
			int width = 1280, 
			int height = 1080,
			bool fullscrn = false, 
			bool vsync = true
		);
	~Display();

	void cursor_enter_callback(int entered)
	{	
		cursor_focus_status = entered;
	}

	int get_height();
	int get_width();
	int get_focus_status();
	GLFWwindow* get_window();

	void set_dimensions(int width, int height);
};

#endif