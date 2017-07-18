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
#include <glm/glm.hpp>

/*
	Internal Headers
*/
#include <display_manager.hpp>
#include <render_manager.hpp>
#include <input_manager.hpp>
#include <shader.hpp>

/*
	Gloabl Variables
*/

int main(int argc, char *argv[]) {

	int width, height;

	DisplayManager display  = DisplayManager("testing", false);
	RenderManager  renderer = RenderManager();
	InputManager   inputs   = InputManager();

	Shader shader = Shader("basic");

	// display settings


	// render settings
	//renderer.set_bkg_clr(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));	

	// input settings


	// setup methods
	renderer.setup();

float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
}; 

	while(glfwGetKey(display.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display.window)) 
	{
		inputs.poll();
		renderer.update(display.window);
	}

	return EXIT_SUCCESS;
}