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

/*
	Internal Headers
*/
#include <display_manager.hpp>

/*
	Gloabl Variables
*/


int main(int argc, char *argv[]) {

	DisplayManager display = DisplayManager("testing");

	// opengl settings
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	while(glfwGetKey(display.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display.window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(display.window);
        glfwPollEvents();
	}

	return EXIT_SUCCESS;
}