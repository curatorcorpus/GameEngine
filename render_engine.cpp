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
#include <camera.hpp>
#include <controls.hpp>
#include <display.hpp>
#include <master_renderer.hpp>
#include <model.hpp>
#include <model_loader.hpp>
#include <shader.hpp>

/*
	Gloabl Variables
*/
static const int W_WIDTH  = 2560;
static const int W_HEIGHT = 1440;

int main(int argc, char *argv[]) 
{
	// initialize engine components.
	Display* 	    display  = new Display("Game Engine", W_WIDTH, W_HEIGHT);
	Camera*  	    camera   = new Camera();
	GLFWwindow*     window   = display->get_window();
	Controls* 	    controls = new Controls(camera, window);
	MasterRenderer* renderer = new MasterRenderer();

	// add models to render
	renderer->add_model("katarina", "basic");

	// setup engine properties.
	renderer->setup();

	// main engine loop.
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window))
	{  
		controls->update();
		renderer->update(window, camera);
	}

	delete display;
	delete controls;
	delete renderer;
	delete camera;

	return EXIT_SUCCESS;
}