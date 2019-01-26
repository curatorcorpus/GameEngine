#include <master_renderer.hpp>

MasterRenderer::MasterRenderer()
{
	this->objects.clear();
	
	// construct shaders.
	this->default_shader = new Shader("default");
	this->terrain_shader = new Shader("terrain");
}

MasterRenderer::~MasterRenderer()
{
	delete default_shader;
	delete terrain_shader;
	delete fps_counter;
}

void MasterRenderer::add_object(Object* object) 
{
	object->setup(default_shader);
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
	fps_counter = new FpsCounter();
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