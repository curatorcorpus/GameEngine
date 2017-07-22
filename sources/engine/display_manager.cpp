#include <display_manager.hpp>

DisplayManager::DisplayManager(std::string title, bool fullscrn, int width, int height) {

	this->width = width;
	this->height = height;

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
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	// open window and create opengl context
	if(fullscrn)
		window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), NULL);
	else 
		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if(window == NULL) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	// initialize glew opengl extension libraries.
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // info opengl of viewport
    glViewport(0, 0, width, height);
}

DisplayManager::~DisplayManager() {
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cerr << "[DEBUG::DISPLAY_MANAGER] Window terminated!" << std::endl;
}

int DisplayManager::get_height() {
	return this->height;
}

int DisplayManager::get_width() {
	return this->width;
}

void DisplayManager::set_dimensions(int width, int height) {

	this->width = width;
	this->height = height;
}