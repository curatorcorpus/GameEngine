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

	// DATA FIELDS
	std::string name;
	glm::mat4 transform;
	std::vector<Mesh> meshes;
	Shader* shader;

	// OVERRIDE-ABLE METHODS

	// METHODS
	void set_meshes();

public:

	// CONSTRUCTORS
	Model();
	Model(std::string name);

	// DESTRUCTOR
	~Model();
	
	// OVERRIDE-ABLE METHODS
	virtual void render(Camera* camera, glm::mat4& vp);
	virtual void setup(Shader* shader);

	// METHODS
	void add_mesh(Mesh mesh);
	void reserve_list(int size);// TODO
	void translate(glm::vec3 translation);
	void rotate(float angle); // TODO
	void rotate_x(float angle); // TODO
	void rotate_y(float angle); // TODO
	void rotate_z(float angle); // TODO
	void scale(); // TODO
	void reset_transform();

	// GETTERS
	std::string get_name();// TODO
	glm::mat4 get_transform();// TODO

	// SETTERS
	void set_transform(glm::mat4 transform);
};

#endif