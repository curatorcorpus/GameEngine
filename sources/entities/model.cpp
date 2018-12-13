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
	this->shader = new Shader(shader_name);
}

Model::~Model() {
/*
	for(int i = 0; i < size; i++) 
	{
		delete meshes[i];
	}

	if(shader != nullptr) 
	{
		std::cerr << "test" << std::endl;
	
		delete shader;
	}*/
}

void Model::add_mesh(Mesh* mesh) 
{
	meshes.push_back(mesh);
}

void Model::render(Camera* camera) 
{
	for(int i = 0; i < size; i++) 
	{
		meshes[i]->render(camera);
	}
}

void Model::reserve_list(int size) 
{
	this->size = size;
	this->meshes.reserve(size);
}

void Model::setup_meshes() 
{
	for(int i = 0; i < size; i++) 
	{
		meshes[i]->set_shader(shader);
		meshes[i]->setup();
	}
}

void Model::clean_up()
{
	for(int i = 0; i < size; i++) 
	{
		delete meshes[i];
	}

	if(shader != nullptr) 
	{
		delete shader;
	}
}