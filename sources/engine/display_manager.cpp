#include <display_manager.hpp>

DisplayManager::DisplayManager(std::string title, int width = 1280, int height = 1080) {
	// initialize GLFW window
	if(!glfwInit()) {
		std::cerr << "[DEBUG::DISPLAY_MANAGER] " 
				  << "Failed to intialize GLFW Context" 
				  << 
		std::endl;

		exit(EXIT_FAILURE);
	}

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// open window and create opengl context
	window = glfwCreateWindow(1280, 900, title.c_str(), glfwGetPrimaryMonitor(), NULL);
	if(window == NULL) {
		glfwTerminate();

		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
}

DisplayManager::~DisplayManager() {
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cerr << "[DEBUG::DISPLAY_MANAGER] Window terminated!" << std::endl;
}