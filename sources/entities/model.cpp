#include <model.hpp>

Model::Model()
{
	this->name = "no_name";
	this->meshes.clear();
	this->transform = glm::mat4(1.0f);
}

Model::Model(std::string name)
{
	this->name = name;
	this->meshes.clear();
	this->transform = glm::mat4(1.0f);
}

Model::~Model() {}

// PUBLIC METHODS

/*
	Method for setting up model for rendering with basic shaders.
*/
void Model::setup(Shader* shader)
{
	if(shader == nullptr) 
    {
		std::cerr << "[DEBUG::MESH] " + name + "failed to reference shader!" << std::endl;
		return; 
	}
	this->shader = shader;

	set_meshes();
}

/*
	Main render method for models.
*/
void Model::render(Camera* camera, glm::mat4& vp) 
{
	// Update transform.
	glm::mat4 mvp = vp * this->transform;

	// Update MVP and camera pos in bound shader.
	shader->update_mvp(mvp);
	shader->update_cam_pos(camera->get_pos());
	
	// Render mesh.
	for(int i = 0; i < meshes.size(); i++) 
		meshes[i].render();
}

/*
	Method for adding associated meshes for this 3D model to be rendered.
*/
void Model::add_mesh(Mesh mesh) 
{
	meshes.push_back(mesh);
}

/*
	Method for obtaining current tranformation matrix.
*/
glm::mat4 Model::get_transform()
{
	return transform;
}

/*
	Method for reseting model transform back to the identity matrix.
*/
void Model::reset_transform()
{
	this->transform = glm::mat4(1.0f);
}

/*
	Method for translating model.
*/
void Model::translate(glm::vec3 translation)
{
	this->transform = glm::translate(transform, translation);
}

// PRIVATE METHODS

/*
	Method for setting up VAO and VBOs for mesh related data.
	[TODO]: May be overkill for one VAO per Model. Maybe need optimization later.
*/
void Model::set_meshes() 
{
	for(int i = 0; i < meshes.size(); i++) 
		meshes[i].setup();
}