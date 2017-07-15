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
	Gloabl Variables
*/
GLFWwindow* create_window(std::string title) {

	// initialize GLFW window
	if(!glfwInit()) {
		std::cerr << "[DEBUJG::RENDER_ENGINE] " 
				  << "Failed to intialize GLFW Context" 
				  << 
		std::endl;

		exit(EXIT_FAILURE);
	}

	// open window and create opengl context
	GLFWwindow* window = glfwCreateWindow(1280, 900, title.c_str(), NULL, NULL);
	if(window == NULL) {
		glfwTerminate();

		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	return window;
}

int main(int argc, char *argv[]) {

	GLFWwindow* window = create_window("Test");

	while(!glfwWindowShouldClose(window)) 
	{

	}

	return EXIT_SUCCESS;
}