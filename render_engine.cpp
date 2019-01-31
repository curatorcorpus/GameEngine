/*
	C++ Libraries
*/
#include <iostream>

/*
	C Libraries
*/
//#include <stdlib.h>
//#include <stdio.h>

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
#include <shader.hpp>
#include <terrain.hpp>
#include <light.hpp>

/*
	Gloabl Variables
*/
static const int W_WIDTH  = 1920;
static const int W_HEIGHT = 1080;

int main(int argc, char *argv[]) 
{
	// initialize engine components.
	Display display("Game Engine", W_WIDTH, W_HEIGHT, false, false);
	Camera camera;
	GLFWwindow* window = display.get_window();
	Controls controls(&camera, window);
	MasterRenderer renderer;
	Light light(glm::vec3(0.0f, 100000.0f, 0.0f));

	// Master renderer settings.
	Object kat("katarina","katarina_base_diffuse");
	//Object katx("katarina","katarina_base_diffuse");
	// katy("katarina","katarina_base_diffuse");
	//Object katz("katarina","katarina_base_diffuse");
	//Object kat_x("katarina","katarina_base_diffuse");
	//Object kat_y("katarina","katarina_base_diffuse");
	//Object kat_z("katarina","katarina_base_diffuse");
	Terrain terrain("grasss");

	renderer.add_object(&kat);
	//renderer.add_object(&katx);
	///renderer.add_object(&katy);
	//renderer.add_object(&katz);
	//renderer.add_object(&kat_x);
	//renderer.add_object(&kat_y);
	//renderer.add_object(&kat_z);

	//katx.translate(glm::vec3(5.0,0,0));
	//katy.translate(glm::vec3(0,5.0,0));
	//katz.translate(glm::vec3(0,0,5.0));

	//kat_x.translate(glm::vec3(-5.0,0,0));
	//kat_y.translate(glm::vec3(0,-5.0,0));
	//kat_z.translate(glm::vec3(0,0,-5.0));

	renderer.add_terrain(&terrain);

	renderer.set_light(&light);

	// setup engine properties.
	renderer.setup();

	// main engine loop.
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window))
	{
		if(!display.get_focus_status()) glfwWaitEvents();glfwPostEmptyEvent();

		controls.update();
		renderer.update(window, &camera); 
	}

	return EXIT_SUCCESS;
}