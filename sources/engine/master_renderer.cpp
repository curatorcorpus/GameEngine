#include <master_renderer.hpp>

MasterRenderer::MasterRenderer() {

	this->models.clear();
}

MasterRenderer::~MasterRenderer() {

	for(int i = 0; i < models.size(); i++)
	{
		delete models[i];
	}

	delete fps_counter;
}

void MasterRenderer::setup() {

	ModelLoader loader = ModelLoader();

	Model* model = new Model("basic");
	loader.load_obj("katarina", model);
	model->setup_meshes();

	// for now just specify number of models.
	models.push_back(model);

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