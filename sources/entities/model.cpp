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
}

void Model::render(Camera* camera) 
{
	for(int i = 0; i < size; i++) 
	{
		meshes[i].render(camera);
	}
}

/*void Model::reserve_list(int size) 
{
	this->size = size;
	this->meshes.reserve(size);
}*/

void Model::setup_meshes() 
{
	for(int i = 0; i < size; i++) 
	{	
		std::cout << "[Model::setup_meshes]" << std::endl;
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
	if(shader != nullptr) 
	{
		delete shader;
	}
}

void Model::reset_transform()
{
	this->transform = glm::mat4(1.0f);
}

void Model::translate(glm::vec3 translation)
{
	this->transform = glm::translate(transform, translation);
}