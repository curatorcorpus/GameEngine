#include <master_renderer.hpp>

MasterRenderer::MasterRenderer()
{
	this->objects.clear();
	
	// construct shaders.
	this->object_shader = new ObjectShader();
	this->terrain_shader = new TerrainShader();

	// load skybox components.
	this->cubemap = new CubeMap("cloudy_skies");

	// load diagnostics.
	this->fps_counter = new FpsCounter();
}

MasterRenderer::~MasterRenderer()
{
	delete cubemap;
	delete fps_counter;
	delete object_shader;
	delete terrain_shader;
}

void MasterRenderer::add_object(Object* object) 
{
	object->setup(object_shader);
	objects.push_back(object);
}

void MasterRenderer::add_terrain(Terrain* terrain)
{
	terrain->setup(terrain_shader);
	terrains.push_back(terrain);
}

void MasterRenderer::set_light(Light* light) 
{
	this->light = light;
}

void MasterRenderer::setup() 
{
	for(int i = 0; i < objects.size(); i++)
	{
		objects[i]->set_meshes();
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->set_meshes();
	}
}

void MasterRenderer::update(GLFWwindow* window, Camera* camera) 
{ 
	fps_counter->update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i = 0; i < objects.size(); i++) 
	{
		objects[i]->render(camera);
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->render(camera);
	}

	glfwPollEvents();
	glfwSwapBuffers(window);

	fps_counter->count_fps();
}