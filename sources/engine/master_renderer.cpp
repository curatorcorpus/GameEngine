#include <master_renderer.hpp>

/*
	Constructor where you pass camera object (which you want to
	render to) as parameter.
*/
MasterRenderer::MasterRenderer(Camera* camera)
{
	this->fps_on = true;

	this->objects.clear();
	this->camera = camera;

	// Load shaders.
	this->object_shader  = new ObjectShader();
	this->skybox_shader  = new SkyboxShader();
	this->terrain_shader = new TerrainShader();

	// Load skybox.
	this->skybox = new Skybox();

	// Load diagnostics.
	this->hrs_timer = new HRSTimer();
	this->fps_counter = new FpsCounter();
}

/*
	Default destructor.
*/
MasterRenderer::~MasterRenderer()
{
	delete hrs_timer;
	delete fps_counter;


	delete skybox;

	// delete shaders.
	delete object_shader;
	delete skybox_shader;
	delete terrain_shader;
}

/*
	Method for adding 3D model objects to render pipeline.
*/
void MasterRenderer::add_object(Object* object) 
{
	objects.push_back(object);
}

/*
	Method for adding terrain objects to render pipeline.
*/
void MasterRenderer::add_terrain(Terrain* terrain)
{
	terrain->setup(terrain_shader);
	terrains.push_back(terrain);
}

/*
	Method for adding directional lighting.
*/
void MasterRenderer::set_light(Light* light) 
{
	this->light = light;
}

/*

*/
void MasterRenderer::setup() 
{
	// Setup Skybox.
	this->skybox->setup(skybox_shader, camera->get_proj_mat());

	for(int i = 0; i < objects.size(); i++)
		objects[i]->setup(object_shader);
		
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->set_meshes();
	}
}

/*
	Main method which is called every frame.
*/
void MasterRenderer::update(GLFWwindow* window) 
{ 
	if(fps_on)
		fps_counter->update();

	// Clears main frame buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 mvp = camera->get_view_proj_mat();

	// Update objects.
	for(int i = 0; i < objects.size(); i++) 
	{
		object_shader->bind();
		hrs_timer->init();
		objects[i]->render(this->camera, mvp);
		hrs_timer->end();

		hrs_timer->print_nano();
		hrs_timer->print_micro();
		hrs_timer->print_milli();
		hrs_timer->print_secs();
		
		object_shader->unbind();
	}

	// Update terrains.
	for(int i = 0; i < terrains.size(); i++)
	{

		terrains[i]->render(this->camera);
	}

	// Update skybox.
	skybox->render(this->camera);

	glfwPollEvents();		 // Process all events.
	glfwSwapBuffers(window); // Swap between front and back buffer.

	if(fps_on)
		fps_counter->count_fps();
}

/*
	Method for toggling frames per second counter.
*/
void MasterRenderer::toggle_fps()
{
	this->fps_on = !fps_on;
}