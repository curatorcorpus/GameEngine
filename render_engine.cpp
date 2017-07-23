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

int main(int argc, char *argv[]) {

	// initialize engine.
	Display*        display  = new Display("test", false, 1920, 1080);
	Camera*         camera   = new Camera();
	Controls*       controls = new Controls(camera, display->window);	
	MasterRenderer* renderer = new MasterRenderer();
	
	// setup engine properties.
	renderer->setup();

	// main engine loop.
	while(glfwGetKey(display->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display->window)) 
	{  
		controls->update();
		renderer->update(display->window, camera);
	}

	// tidy engine memory.
	delete camera;
	delete controls;
	delete renderer;
	delete display;

	return EXIT_SUCCESS;
}