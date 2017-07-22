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

	int frames = 0;
	double init_time = glfwGetTime();
	double curr_time, last_time = 0.0;

	DisplayManager* display = new DisplayManager("test", false);

	// Dark blue background
	glfwSetInputMode(display->window, GLFW_STICKY_KEYS, GL_TRUE);  

    glEnable(GL_DEPTH_TEST);              // Enable depth test
    glDepthFunc(GL_LESS);                 // Accept fragment if it closer to the camera than the former ones
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.4f, 0.0f, 1.0f);

	Camera* camera = new Camera();
	Controls controls = Controls(camera, display->window);

	Shader* shader = new Shader("basic");
	Mesh* mesh = new Mesh();

	ModelLoader loader = ModelLoader();

	loader.load_obj("dragon", mesh);

	mesh->set_shader(shader);
	mesh->setup();

	while(glfwGetKey(display->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display->window)) 
	{  
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		controls.update();
		mesh->render(camera);

		glfwSwapBuffers(display->window);
		glfwPollEvents();
	}

	delete shader;
	delete mesh;
	delete camera;
	delete display;

	return EXIT_SUCCESS;
}