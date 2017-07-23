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
#include <controls.hpp>
#include <model.hpp>
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

	int frames = 0;
	double init_time = glfwGetTime();
	double curr_time, last_time = 0.0;

	DisplayManager* display = new DisplayManager("test", false, 1920, 1080);

	Camera* camera = new Camera();
	Controls controls = Controls(camera, display->window);
	Model* model = new Model();

	ModelLoader loader = ModelLoader();
	loader.load_obj("katarina", model);

	model->setup_meshes();

	while(glfwGetKey(display->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display->window)) 
	{  
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		controls.update();
		model->render(camera);

		//fps_counter();
		
		glfwSwapBuffers(display->window);
		glfwPollEvents();
	}

	delete model;
	delete camera;
	delete display;

	return EXIT_SUCCESS;
}