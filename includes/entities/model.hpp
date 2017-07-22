#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <mesh.hpp>

class Model : public Object {

private:

	int size;

	std::vector<Mesh*> meshes;

public:

	Model();
	Model(int size);
	~Model();

	void add_mesh(Mesh* mesh);
	void render(Camera* camera);
	void reserve_list(int size);	
	void setup_meshes();
};

#endif