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

class RenderManager {

private:

public:
	RenderManager();
	~RenderManager();

	void setup_gl_states();
	void update();
};

#endif