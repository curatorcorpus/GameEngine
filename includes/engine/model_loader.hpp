#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include <mesh.hpp>
#include <model.hpp>
#include <textured_model.hpp>

class ModelLoader {

private:

	const char* Model_Path   = "../resources/models/";
	const char* Model_Suffix = ".obj";

public:

	ModelLoader();
	~ModelLoader();

	Model* load_obj(std::string path, const std::string& shader_name);
	TexturedModel* load_textured_obj(std::string name, std::string texture_name, const std::string& shader_name);
};

#endif