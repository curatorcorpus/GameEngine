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

/*

*/
#include <camera.hpp>
#include <light.hpp>
#include <loader.hpp>
#include <shader.hpp>
#include <terrain.hpp>
#include <object.hpp>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include <fps_counter.hpp> // crashes program if included elsewhere. has to do with glew.

class MasterRenderer {

private:

	std::vector<Object*> objects;
	std::vector<Terrain*> terrains;

	FpsCounter* fps_counter;
	Light* light;
	Shader* default_shader;
	Shader* terrain_shader;

public:
	MasterRenderer();
	~MasterRenderer();

	// setters and getters

	void add_model(std::string model_name);
	void add_object(Object* object);
	void add_terrain(Terrain* terrain);
	void set_light(Light* light);
	void setup();
	void update(GLFWwindow* window, Camera* camera);
};

#endif