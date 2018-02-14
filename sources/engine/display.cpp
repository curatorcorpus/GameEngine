#include <display.hpp>

Display::Display(std::string title, int width, int height,
									bool fullscrn, bool vsync) {

	this->title    = title;
	this->width    = width;
	this->height   = height;
	this->fullscrn = fullscrn;
	this->vsync    = vsync;

	setup_glfw();
	setup_glew();
    setup_opengl();
}

Display::~Display() 
{
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cerr << "[DEBUG::DISPLAY_MANAGER] Window terminated!" << std::endl;
}

void Display::setup_glfw() 
{
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
	if(this->fullscrn)
		this->window = glfwCreateWindow(
										this->width, 
										this->height, 
										this->title.c_str(), 
										glfwGetPrimaryMonitor(), NULL);
	else 
		this->window = glfwCreateWindow(this->width, 
										this->height, 
										this->title.c_str(), NULL, NULL);

	if(this->window == NULL) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	// glfw settings
	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE); 
	
	if(vsync) 
		glfwSwapInterval(0);		 				// vsync

}

void Display::setup_glew() 
{
	// initialize glew opengl extension libraries.
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void Display::setup_opengl() 
{
	// opengl settings
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.4f, 0.0f, 1.0f);
	glDepthFunc(GL_LESS);                 // Accept fragment if it closer to the camera than the former ones
    glEnable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);              // Enable depth test
	glViewport(0, 0, width, height);
}

int Display::get_height() 
{
	return this->height;
}

int Display::get_width() 
{
	return this->width;
}

GLFWwindow* Display::get_window()
{
	return window;
}

void Display::set_dimensions(int width, int height) 
{
	this->width = width;
	this->height = height;
}