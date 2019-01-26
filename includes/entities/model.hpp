#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <mesh.hpp>
#include <shader.hpp>

class Model {

protected:
	
	int size;

	glm::mat4 transform;
	std::string shader_name;
	std::vector<Mesh> meshes;
	Shader* shader;

public:

	Model();
	Model(std::string shader_name);
	Model(int size);
	~Model();

	void clean_up();
	void add_mesh(Mesh mesh);
	virtual void render(Camera* camera);
	void reserve_list(int size);	
	void set_meshes();
	void set_shader(Shader* shader);
	void set_texture();

	void translate(glm::vec3 translation);
	void rotate();
	void scale();
	void reset_transform();

	glm::mat4 get_transform();

	void set_transform(glm::mat4 transform);
};

#endif