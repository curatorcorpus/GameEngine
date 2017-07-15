#include <render_manager.hpp>

RenderManager::RenderManager() {

}

RenderManager::~RenderManager() {

}

void RenderManager::setup_gl_states() {
	// opengl settings
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void RenderManager::update() { 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

