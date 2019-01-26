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

/*
	External Libraries
*/
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Controls {

private:

	Camera* camera;
	GLFWwindow* window;

	int width, height;

	float key_speed;
	float mouse_speed;
	float horizontal_angle;
	float vertical_angle;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Controls* test = static_cast<Controls*>(glfwGetWindowUserPointer(window));
		test->key_callback(key, scancode, action, mods);
	}

public:
	Controls(Camera* camera, GLFWwindow* window);
	~Controls();

	// Used more for an interrupt event.
	void key_callback(int key, int scancode, int action, int mods)
	{
		if(key == GLFW_KEY_F12 && action == GLFW_PRESS)
		{
			std::cerr << "[DEBUG::CONTROLS] Screenshot saved!" << std::endl;
			int w = 1280;
			int h = 1080;
			std::string file_name = "./test.png";
			uint8_t *pixels = new uint8_t[w * h * 3];
			glReadPixels(0, 0, 1280, 1080, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)pixels);

		    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
			if (!png)
				return;

			png_infop info = png_create_info_struct(png);
			if (!info) {
				png_destroy_write_struct(&png, &info);
				return ;
			}

			FILE *fp = fopen(file_name.c_str(), "wb");
			if (!fp) {
				png_destroy_write_struct(&png, &info);
				return;
			}

			png_init_io(png, fp);
			png_set_IHDR(png, info, w, h, 8 /* depth */, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
				PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
			png_colorp palette = (png_colorp)png_malloc(png, PNG_MAX_PALETTE_LENGTH * sizeof(png_color));
			if (!palette) {
				fclose(fp);
				png_destroy_write_struct(&png, &info);
				return;
			}
			png_set_PLTE(png, info, palette, PNG_MAX_PALETTE_LENGTH);
			png_write_info(png, info);
			png_set_packing(png);

			png_bytepp rows = (png_bytepp)png_malloc(png, h * sizeof(png_bytep));
			for (int i = 0; i < h; ++i)
				rows[i] = (png_bytep)(pixels + (h - i - 1 ) * w * 3);

			png_write_image(png, rows);
			png_write_end(png, info);
			png_free(png, palette);
			png_destroy_write_struct(&png, &info);

			fclose(fp);
			delete[] rows;
			return;
		}
	}

	void update();
};

#endif