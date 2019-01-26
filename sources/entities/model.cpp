#include <model.hpp>

Model::Model()
{
	this->meshes.clear();
	this->transform = glm::mat4(1.0f);
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
}

void Model::render(Camera* camera) 
{	
	shader->bind();

	//glm::mat4 model = this->get_transform();
	glm::mat4 mvp = camera->get_view_proj_mat();// * model;
    //std::cout << glm::to_string(model) << std::endl;
	shader->update_mvp(mvp);
	shader->update_cam_pos(camera->get_pos());

	//std::cerr<<"[DEBUG::MODEL::RENDER]"<<std::endl;
	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render();
	}

	shader->unbind();
}

void Model::reserve_list(int size) 
{
	this->size = size;
	this->meshes.reserve(size);
}

void Model::set_meshes() 
{
	for(int i = 0; i < meshes.size(); i++) 
	{	
		std::cerr << "[Model::SETUP_MESHES] " << shader->get_prog_id() << std::endl;
		meshes[i].setup();
	}
}

void Model::set_shader(Shader* shader)
{
	if(shader == nullptr) 
    {
//		std::cerr << "[DEBUG::MESH_CPP]" + name + "failed to reference shader!" << std::endl; 
	}
	this->shader = shader;
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