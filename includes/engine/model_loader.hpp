#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include <mesh.hpp>

class ModelLoader {

private:



public:

	ModelLoader();
	~ModelLoader();

	bool load_obj(const char* path);
};


#endif