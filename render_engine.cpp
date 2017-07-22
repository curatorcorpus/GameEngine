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

	int frames = 0;
	double init_time = glfwGetTime();
	double curr_time, last_time = 0.0;

	DisplayManager* display = new DisplayManager("test", false);

	// Dark blue background
	glfwSetInputMode(display->window, GLFW_STICKY_KEYS, GL_TRUE);  
//dglViewport(0, 0, 1280, 720);
    glEnable(GL_DEPTH_TEST); 
	float vertices[] = { 
		-0.5f, 0.5f, 0.0f, 
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f, 

		 0.5f, -0.5f, 0.0f, 
		 0.5f, 0.5f, 0.0f, 
		 -0.5f, 0.5f, 0.0f
 
	};

	GLuint vao_id; 
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);

	GLuint vbo_id;
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, 
				 sizeof(vertices), 
				 vertices, 
				 GL_STATIC_DRAW);

	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	while(glfwGetKey(display->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(display->window)) 
	{  
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer( // verts
							0,        // attribute
                            3,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );	

		glDrawArrays(GL_TRIANGLES, 0, 18);

		glDisableVertexAttribArray(0);

		glfwSwapBuffers(display->window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &vbo_id);
	glDeleteVertexArrays(1, &vao_id);

	delete display;

	return EXIT_SUCCESS;
}