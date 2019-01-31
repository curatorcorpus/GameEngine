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
#include <object.hpp>
#include <object_shader.hpp>
#include <terrain.hpp>
#include <terrain_shader.hpp>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include <fps_counter.hpp> // crashes program if included elsewhere. has to do with glew.

class MasterRenderer {

private:
	
	// DATA FIELDS
	std::vector<Object*> objects;
	std::vector<Terrain*> terrains;

	FpsCounter* fps_counter;
	Light* light;
	ObjectShader* object_shader;
	TerrainShader* terrain_shader;

public:
	MasterRenderer();
	~MasterRenderer();

	void add_model(std::string model_name);
	void add_object(Object* object);
	void add_terrain(Terrain* terrain);
	void setup();
	void update(GLFWwindow* window, Camera* camera);

	// GETTERS
	

	// SETTERS
	void set_light(Light* light);
};

#endif