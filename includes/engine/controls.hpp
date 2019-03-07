#ifndef CONTROLS_HPP
#define CONTROLS_HPP

/*
	C++ Libraries
*/
#include <iostream>

/*
	C Libraries
*/
#include <stdlib.h>
#include <stdio.h>
#include <png.h>

#include <camera.hpp>
#include <img_writer.hpp>

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Controls {

private:

	// CONSTANTS
	static constexpr float ROT_LIMIT = 1.5f;
	static constexpr float MOV_LIMIT = 0.0f;
	static constexpr float AWSD_UPPER_LIMIT = 100.0f;
	static constexpr float AWSD_LOWER_LIMIT = 10.0f;

	// STATIC DATAFIELDS.
	static float AWSD_SPEED;

	// DATAFIELDS
	Camera* camera;
	GLFWwindow* window;

	int width, height;

	float mouseRot_speed;
	float horizontal_angle;
	float vertical_angle;

	// CALLBACKS
	
	/*
		Callback method for keyboard inputs. 
	 */
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Controls* test = static_cast<Controls*>(glfwGetWindowUserPointer(window));
		test->key_callback(key, scancode, action, mods);
	}

	/*
		Callback method for scroll up/down inputs.
	*/
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Controls* test = static_cast<Controls*>(glfwGetWindowUserPointer(window));
		test->scroll_callback(xoffset, yoffset);
	}

    // OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS


    // SETTERS

public:

    // CONSTRUCTORS
    Controls(Camera* camera, GLFWwindow* window);

	// DECONSTRUCTOR
	~Controls();

	// CALLBACKS

	// Used more for an interrupt event.
	void key_callback(int key, int scancode, int action, int mods)
	{
		// Reads current pixels in the frame buffer and saves it as png to disk.
		if(key == GLFW_KEY_F12 && action == GLFW_PRESS)
		{
			int w = 1920;
			int h = 1080;
			std::string file_name = "./test.png";
			//glfwGetWindowSize(window, &w, &h); [THIS BREAKS]
		
			uint8_t *pixels = new uint8_t[w * h * 3];
			glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)pixels);
			ImgWriter::save_png(file_name, w, h, pixels);

			std::cerr << "[DEBUG::CONTROLS] Screenshot saved!" << std::endl;
		}
	}

	void scroll_callback(double xoffset, double yoffset)
	{
		// Increase/decrease AWSD movement speed. 
		AWSD_SPEED += (float)yoffset * 2.0f;

		// Cap AWSD movement speed upper and lower.
		if(AWSD_SPEED >= AWSD_UPPER_LIMIT)
			AWSD_SPEED = AWSD_UPPER_LIMIT;
		else if(AWSD_SPEED < AWSD_LOWER_LIMIT)
			AWSD_SPEED = AWSD_LOWER_LIMIT;
	}

	// METHODS
	void update();

	// GETTERS


    // SETTERS
};

#endif