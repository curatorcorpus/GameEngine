#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

#include <mesh.hpp>

class Model : public Object {

private:

	std::vector<Mesh*> meshes;

public:

	Model();
	~Model();


};

#endif