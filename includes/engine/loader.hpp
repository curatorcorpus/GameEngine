#ifndef LOADER_HPP
#define LOADER_HPP

#include <iostream>
#include <vector>
#include <png.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include <mesh.hpp>
#include <model.hpp>

class Loader {

	static constexpr const char* const Model_Path   = "../resources/models/";
	static constexpr const char* const Texture_Path = "../resources/textures/";
	static constexpr const char* const Model_Suffix = ".obj";
	static constexpr const char* const PNG_Suffix   = ".png";

public:
	typedef struct texture_info
	{
		GLuint	 		id;
		std::string 	name;
		uint			width;
		uint			height;
		unsigned char*  data;
		bool 		    is_loaded;
	} texture_info;

	static void load_obj(std::string name, Model* model);
	static void load_PNG(texture_info* tex_info);
};

#endif