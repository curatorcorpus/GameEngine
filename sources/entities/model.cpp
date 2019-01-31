#include <model.hpp>

Model::Model()
{
	this->name = "no_name";
	this->meshes.clear();
	this->transform = glm::mat4(1.0f);
}

Model::~Model() {}

void Model::add_mesh(Mesh mesh) 
{
	meshes.push_back(mesh);
}

void Model::render(Camera* camera) 
{	
	shader->bind();

	//glm::mat4 model = this->transform;
	glm::mat4 mvp = camera->get_view_proj_mat();// * model;
	shader->update_mvp(mvp);
	shader->update_cam_pos(camera->get_pos());
	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render();
	}

	shader->unbind();
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
		std::cerr << "[DEBUG::MESH] " + name + "failed to reference shader!" << std::endl;
		return; 
	}
	this->shader = shader;
}

void Model::reset_transform()
{
	this->transform = glm::mat4(1.0f);
}

void Model::translate(glm::vec3 translation)
{
	this->transform = glm::translate(transform, translation);
}