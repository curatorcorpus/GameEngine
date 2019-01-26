#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include <mesh.hpp>
#include <model.hpp>
#include <textured_model.hpp>

class Loader {

	static constexpr const char* const Model_Path   = "../resources/models/";
	static constexpr const char* const Texture_Path = "../resources/textures/";
	static constexpr const char* const Model_Suffix = ".obj";
	static constexpr const char* const PNG_Suffix   = ".png";

private:

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

	static Model* load_obj(std::string path, const std::string& shader_name);
	static Model* load_textured_obj(std::string name, std::string texture_name);
	static void load_PNG(texture_info* tex_info);
};

#endif