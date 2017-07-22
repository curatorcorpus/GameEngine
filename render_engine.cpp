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
#include <display_manager.hpp>
#include <render_manager.hpp>
#include <input_manager.hpp>
#include <mesh.hpp>
#include <model_loader.hpp>
#include <shader.hpp>

/*
	Gloabl Variables
*/

/**
    Simple fps counter.
*/
static void fps_counter(double& current_time, double& initial_time, int& frames) {
    
    if(current_time - initial_time >= 1.0) {
        printf("%.1f ms per frame | %d frames\n", 1000.0/double(frames), frames);

        frames = 0;
        initial_time++;
    }
}

int main(int argc, char *argv[]) {

	int width, height;

	DisplayManager display  = DisplayManager("testing", false);
	RenderManager  renderer = RenderManager();

	Camera* camera = new Camera();

	InputManager inputs = InputManager(camera, display.window);

	Shader* shader = new Shader("basic");
	
	ModelLoader loader = ModelLoader();


	Mesh* mesh = new Mesh();

	if(loader.load_obj("katarina", mesh)) {

		std::cout << "worked" << std::endl; 
	}
	mesh->set_shader(shader);
	mesh->setup();

	// display settings


	// render settings
	//renderer.set_bkg_clr(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));	

	// input settings


	// setup methods
	renderer.setup();

	int frames = 0;
	double init_time = glfwGetTime();
	double curr_time, last_time = 0.0;

	while(glfwGetKey(display.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display.window)) 
	{
		curr_time = glfwGetTime();
		
		renderer.update(display.window);
		inputs.update();
		mesh->render(camera);
		fps_counter(curr_time, init_time, (++frames));

		last_time = curr_time;
	}

	delete camera;
	delete shader;
	delete mesh;

	return EXIT_SUCCESS;
}