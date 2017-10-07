#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <mesh.hpp>

class Model {

protected:

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
};

#endif