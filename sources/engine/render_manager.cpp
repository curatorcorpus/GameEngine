#include <render_manager.hpp>

RenderManager::RenderManager() {

	this->bkg_clr = glm::vec4(0.0f, 0.0f, 0.f, 0.0f);
}

RenderManager::~RenderManager() {}

void RenderManager::setup() {
	// opengl settings
	glClearColor(bkg_clr.x, bkg_clr.y, bkg_clr.z, bkg_clr.w);
}

void RenderManager::update(GLFWwindow* window) { 

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		std::cout << "working" << std::endl;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void RenderManager::set_bkg_clr(glm::vec4 bkg_clr) {
	this->bkg_clr = bkg_clr;
}