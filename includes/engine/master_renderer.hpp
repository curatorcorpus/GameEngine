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
//#include <model_loader.hpp>
#include <terrain.hpp>
#include <textured_model.hpp>
#include <light.hpp>

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
	Light* light;
//	ModelLoader loader;

public:
	MasterRenderer();
	~MasterRenderer();

	// setters and getters

	void add_model(std::string model_name);
	void add_terrain(Terrain* terrain);
	void add_textured_model(std::string model_name, std::string texture_name);
	void set_light(Light* light);
	void setup();
	void update(GLFWwindow* window, Camera* camera);
};

#endif