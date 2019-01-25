#include <model.hpp>

Model::Model()
{
	this->meshes.clear();
	this->transform = glm::mat4(1.0f);
	this->size = 0;
}

Model::Model(int size)
{
	Model();

	this->size = size;
}

Model::Model(std::string shader_name)
{
	Model();

	this->shader_name = shader_name;
 	this->shader = new Shader(shader_name);
	//std::cerr << "[DEBUG::MODEL::SHADERNAME] " << shader_name << " ID "<< this->shader->get_prog_id() << std::endl;
	this->size = 0;
}

Model::~Model() 
{
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

void Model::add_mesh(Mesh mesh) 
{
	meshes.push_back(mesh);
	this->size += 1;
	std::cerr << "[DEBUG::MODEL] " << size << std::endl;
}

void Model::render(Camera* camera) 
{	
	std::cerr<<"[DEBUG::MODEL::RENDER]"<<std::endl;
	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render(camera);
	}
}

void Model::reserve_list(int size) 
{
	this->size = size;
	this->meshes.reserve(size);
}

void Model::setup_meshes() 
{
	for(int i = 0; i < meshes.size(); i++) 
	{	
		std::cerr << "[Model::SETUP_MESHES] " << shader->get_prog_id() << std::endl;
		meshes[i].set_shader(shader);
		meshes[i].setup();
	}
}

void Model::clean_up()
{
/*	for(int i = 0; i < size; i++) 
	{
		delete meshes[i];
	}
*/
	/*if(shader != nullptr) 
	{
		delete shader;
	}*/
}

void Model::reset_transform()
{
	this->transform = glm::mat4(1.0f);
}

void Model::translate(glm::vec3 translation)
{
	this->transform = glm::translate(transform, translation);
}