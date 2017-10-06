#include <master_renderer.hpp>

MasterRenderer::MasterRenderer() {

	this->models.clear();
}

MasterRenderer::~MasterRenderer() {
/*
	for(int i = 0; i < models.size(); i++)
	{
		delete models[i];
	}*/

	delete fps_counter;
}

void MasterRenderer::add_model(Model* model) 
{
	models.push_back(model);
}

void MasterRenderer::setup() 
{
	for(int i = 0; i < models.size(); i++)
	{
		models[i]->setup_meshes();
	}

	fps_counter = new FpsCounter();
}

void MasterRenderer::update(GLFWwindow* window, Camera* camera) { 

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