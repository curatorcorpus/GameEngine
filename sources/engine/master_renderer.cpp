#include <master_renderer.hpp>

MasterRenderer::MasterRenderer()
{
	this->models.clear();
	
	// construct shaders.
	this->default_shader = new Shader("default");
	this->terrain_shader = new Shader("terrain");
}

MasterRenderer::~MasterRenderer()
{
	for(int i = 0; i < models.size(); i++)
	{
		// free all memory used for storing meshes.
	//	models[i]->clean_up();

		// delete the memory for ptr of model class.
		//delete models[i];
	}

	delete default_shader;
	delete terrain_shader;
	delete fps_counter;
}

void MasterRenderer::add_model(std::string model_name) 
{
/*	Model* loaded_model = loader.load_obj(model_name,"basic");

	if(loaded_model == nullptr)
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP] Failed to load model!" << std::endl;
		return;
	}
	else 
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP]" << " Loaded " << model_name << " model!" << std::endl;
	}

	models.push_back(loaded_model);*/
}

void MasterRenderer::add_textured_model(std::string model_name, std::string texture_name) 
{
	/*Model* loaded_model = Loader::load_textured_obj(model_name, texture_name);

	if(loaded_model == nullptr)
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP] Failed to load model!" << std::endl;
		return;
	}
	else
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP]" << " Loaded " << model_name << " model!" << std::endl;
	}
	loaded_model->set_size(0);
	loaded_model->setup();
	std::cout << "test" << std::endl;
	models.push_back(loaded_model);*/
}

void MasterRenderer::add_terrain(Terrain* terrain)
{
	terrains.push_back(terrain);
}

void MasterRenderer::set_light(Light* light) 
{
	this->light = light;
}

void MasterRenderer::setup() 
{
	for(int i = 0; i < models.size(); i++)
	{
		models[i]->set_meshes();
		models[i]->set_shader(default_shader);
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->set_meshes();
		terrains[i]->set_shader(terrain_shader);
	}
	fps_counter = new FpsCounter();
}

void MasterRenderer::update(GLFWwindow* window, Camera* camera) 
{ 
	fps_counter->update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(int i = 0; i < models.size(); i++) 
	{
		models[i]->render(camera);
	}
	for(int i = 0; i < terrains.size(); i++) 
	{
		terrains[i]->render(camera);
	}
	glfwPollEvents();
	glfwSwapBuffers(window);

	fps_counter->count_fps();
}