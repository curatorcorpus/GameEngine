#include <master_renderer.hpp>

MasterRenderer::MasterRenderer(Camera* camera)
{
	this->objects.clear();
	this->camera = camera;

	// construct shaders.
	this->object_shader  = new ObjectShader();
	this->skybox_shader  = new SkyboxShader();
	this->terrain_shader = new TerrainShader();

	// load skybox.
	this->skybox = new Skybox();

	// load diagnostics.
	this->fps_counter = new FpsCounter();
}

MasterRenderer::~MasterRenderer()
{
	delete fps_counter;
	delete object_shader;
	delete skybox;
	delete skybox_shader;
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
	// Setup Skybox.
	this->skybox->setup(skybox_shader, camera->get_proj_mat());

	for(int i = 0; i < objects.size(); i++)
	{
		objects[i]->set_meshes();
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->set_meshes();
	}
}

void MasterRenderer::update(GLFWwindow* window) 
{ 
	fps_counter->update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i = 0; i < objects.size(); i++) 
	{
		objects[i]->render(this->camera);
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->render(this->camera);
	}

	skybox->render(this->camera);

	glfwPollEvents();
	glfwSwapBuffers(window);

	fps_counter->count_fps();
}