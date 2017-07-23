#ifndef MASTER_RENDERER_HPP
#define MASTER_RENDERER_HPP

/*
	C++ Libraries
*/
#include <iostream>
#include <vector>

/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>

#include <camera.hpp>
#include <model.hpp>
#include <model_loader.hpp>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include <fps_counter.hpp> // crashes program if included elsewhere. has to do with glew.

class MasterRenderer {

private:

	std::vector<Model*> models;

	FpsCounter* fps_counter;

public:
	MasterRenderer();
	~MasterRenderer();

	// setters and getters


	void setup();
	void update(GLFWwindow* window, Camera* camera);
};

#endif