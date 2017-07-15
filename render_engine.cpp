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
#include <render_manager.hpp>
#include <input_manager.hpp>
	
/*
	Gloabl Variables
*/

int main(int argc, char *argv[]) {

	int width, height;

	DisplayManager display  = DisplayManager("testing");
	RenderManager  renderer = RenderManager();
	InputManager   inputs   = InputManager();

	while(glfwGetKey(display.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display.window)) 
	{
		inputs.poll();

		renderer.update();

		glfwSwapBuffers(display.window);
	}

	return EXIT_SUCCESS;
}