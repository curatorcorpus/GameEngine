#include <model.hpp>

Model::Model() {

	this->meshes.clear();

}

Model::Model(int size) {

	Model();

	this->size = size;
}

Model::Model(std::string shader_name) {

	Model();

	this->shader_name = shader_name;
}

Model::~Model() {

	for(int i = 0; i < size; i++) {
		delete meshes[i];
	}

	delete shader;
}

void Model::add_mesh(Mesh* mesh) {

	meshes.push_back(mesh);
}

void Model::render(Camera* camera) {

	for(int i = 0; i < size; i++) {
		meshes[i]->render(camera);
	}
}

void Model::reserve_list(int size) {

	this->size = size;
	this->meshes.reserve(size);
}

void Model::setup_meshes() {

	shader = new Shader(this->shader_name);

	for(int i = 0; i < size; i++) {

		meshes[i]->set_shader(shader);
		meshes[i]->setup();
	}
}