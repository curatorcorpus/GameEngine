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
#include <light.hpp>

/*
	Gloabl Variables
*/
static const int W_WIDTH  = 1920;
static const int W_HEIGHT = 1080;

int main(int argc, char *argv[]) 
{
	// initialize engine components.
	Display* 	    display  = new Display("Game Engine", W_WIDTH, W_HEIGHT, false, false);
	Camera*  	    camera   = new Camera();
	GLFWwindow*     window   = display->get_window();
	Controls* 	    controls = new Controls(camera, window);
	MasterRenderer* renderer = new MasterRenderer();
	Light*			light 	 = new Light(glm::vec3(0.0f, 10.0f, 0.0f));

	// add models to render
	//renderer->add_model("katarina", "basic");

	// Master renderer settings.
	renderer->add_textured_model("katarina","katarina_base_diffuse");
	//renderer->add_textured_model("stall","stallTexture");
	renderer->set_light(light);

	// setup engine properties.
	renderer->setup();

	// main engine loop.
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window))
	{  
		controls->update();
		renderer->update(window, camera);
	}

	delete light;
	delete display;
	delete controls;
	delete renderer;
	delete camera;

	return EXIT_SUCCESS;
}