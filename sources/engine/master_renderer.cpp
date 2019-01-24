#include <master_renderer.hpp>

MasterRenderer::MasterRenderer() 
{
	this->models.clear();
	//this->loader = ModelLoader();
}

MasterRenderer::~MasterRenderer()
{
	/*for(int i = 0; i < models.size(); i++)
	{
		// free all memory used for storing meshes.
		models[i]->clean_up();

		// delete the memory for ptr of model class.
		delete models[i];
	}
	delete fps_counter;*/
}

void MasterRenderer::add_model(std::string model_name) 
{
	/*Model* loaded_model = loader.load_obj(model_name,"basic");

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
	/*TexturedModel* loaded_model = loader.load_textured_obj(model_name,texture_name,"texture");

	if(loaded_model == nullptr)
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP] Failed to load model!" << std::endl;
		return;
	}
	else 
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP]" << " Loaded " << model_name << " model!" << std::endl;
	}
	loaded_model->setup();
	std::cout << "test" << std::endl;
	models.push_back(loaded_model);*/
}

void MasterRenderer::add_terrain(Terrain* terrain)
{
	terrain->setup();
	models.push_back(terrain);
}

void MasterRenderer::set_light(Light* light) 
{
	this->light = light;
}

void MasterRenderer::setup() 
{
	for(int i = 0; i < models.size(); i++)
	{
		models[i]->setup_meshes();
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

	glfwPollEvents();
	glfwSwapBuffers(window);

	fps_counter->count_fps();
}