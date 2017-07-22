#include <render_manager.hpp>

RenderManager::RenderManager() {

	this->bkg_clr = glm::vec4(0.0f, 0.0f, 0.f, 0.0f);
}

RenderManager::~RenderManager() {}

void RenderManager::setup() {

	// opengl settings
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	glEnable(GL_DEPTH_TEST);

	glClearColor(bkg_clr.x, bkg_clr.y, bkg_clr.z, bkg_clr.w);
}

void RenderManager::update(GLFWwindow* window) { 

	glfwPollEvents();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void RenderManager::set_bkg_clr(glm::vec4 bkg_clr) {
	this->bkg_clr = bkg_clr;
}