#ifndef RENDER_MANAGER_HPP
#define RENDER_MANAGER_HPP

/*
	C++ Libraries
*/
#include <iostream>

/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class RenderManager {

private:
	glm::vec4 bkg_clr; // viewport background color

public:
	RenderManager();
	~RenderManager();

	// setters and getters
	void set_bkg_clr(glm::vec4 bkg_clr);

	void setup();
	void update(GLFWwindow* window);
};

#endif