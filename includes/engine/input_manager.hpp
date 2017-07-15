#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

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

class InputManager {

private:

public:
	InputManager();
	~InputManager();

	void poll();
};

#endif