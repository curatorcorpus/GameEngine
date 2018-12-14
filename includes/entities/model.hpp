#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <mesh.hpp>

class Model {

protected:

	glm::mat4 transform;
	int size;

	std::string shader_name;

	std::vector<Mesh*> meshes;

	Shader* shader;

public:

	Model();
	Model(std::string shader_name);
	Model(int size);
	~Model();

	void clean_up();
	void add_mesh(Mesh* mesh);
	void render(Camera* camera);
	void reserve_list(int size);	
	void setup_meshes();

	void translate(glm::vec3 translation);
	void rotate();
	void scale();
	void reset_transform();

	glm::mat4 get_transform();

	void set_transform(glm::mat4 transform);
};

#endif