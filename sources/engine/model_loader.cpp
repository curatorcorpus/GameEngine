#include <model_loader.hpp>


ModelLoader::ModelLoader() {

}

ModelLoader::~ModelLoader() {

}

bool load_obj(std::string& name, Mesh* mesh) {
	
	std::cerr << "[DEBUG::MODEL_LOADER_CPP] Loading Obj File under " << name << std::endl;

	// add full relative path.
	name += "../resources/models/";

	// outputs
	std::vector<glm::vec3> verts;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> norms;

	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(name.c_str(), 0);
	if(!scene) {
		std::cerr << "[DEBUG::MODEL_LOADER_CPP] Failed to load: " << importer.GetErrorString();

		return false;
	}

	for(int i = 0; i < scene->mNumMeshes; i++) {
		std::cerr << i << std::endl;
	}

	return true;
}