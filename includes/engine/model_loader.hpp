#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include <mesh.hpp>
#include <model.hpp>

class ModelLoader {

private:



public:

	ModelLoader();
	~ModelLoader();

	Model* load_obj(std::string path, std::string shader_name);
};

#endif