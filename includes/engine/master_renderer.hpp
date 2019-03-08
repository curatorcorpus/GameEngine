#ifndef MASTER_RENDERER_HPP
#define MASTER_RENDERER_HPP

/*
	C++ Libraries
*/
#include <iostream>
#include <vector>
#include <chrono>
/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>

/*

*/
//#include <hrs_timer.hpp>

#include <cubemap.hpp>
#include <camera.hpp>
#include <light.hpp>
#include <loader.hpp>
#include <object.hpp>
#include <object_shader.hpp>
#include <skybox.hpp>
#include <skybox_shader.hpp>
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
	bool fps_on;

	int ct = 0;
	int avg = 0;
	std::vector<Object*> objects;
	std::vector<Terrain*> terrains;

	Camera* camera;
	CubeMap* cubemap;
	FpsCounter* fps_counter;
	//HRSTimer* hrs_timer;
	Light* light;
	ObjectShader* object_shader;
	Skybox*	skybox;
	SkyboxShader* skybox_shader;
	TerrainShader* terrain_shader;

public:

	// CONSTRUCTORS
	MasterRenderer(Camera* camera);

	// DESTRUCTORS
	~MasterRenderer();

	// METHODS
	void add_model(std::string model_name);
	void add_object(Object* object);
	void add_terrain(Terrain* terrain);
	void setup();
	void update(GLFWwindow* window);
	void toggle_fps();

	// GETTERS
	

	// SETTERS
	void set_light(Light* light);
};

#endif