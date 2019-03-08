#ifndef MESH_HPP
#define MESH_HPP
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <vector>

#include <camera.hpp>
#include <GL/glew.h>
#include <glm/gtx/string_cast.hpp>

class Mesh {

private:

	// DATAFIELDS.

	GLuint vao;

	GLuint vert_buff_id;
	GLuint norm_buff_id;
	GLuint uvs_buff_id;
	GLuint indices_buff_id;

	std::vector<glm::vec3> 	 	verts;
	std::vector<glm::vec3>	 	norms;
	std::vector<glm::vec2>		uvs;
	std::vector<unsigned short> indices;

	// METHODS

public:

	// CONSTRUCTORS
	Mesh();
	Mesh(std::vector<glm::vec3>& verts);
	Mesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& norm, 
		 std::vector<glm::vec2>& uvs,   std::vector<unsigned short>& indices);

	// DESTRUCTORS
	~Mesh();

	// METHODS
	void render();
	void setup();

	// GETTERS
	int get_verts_size();

	// SETTERS
	void set_vertices(std::vector<glm::vec3> verts); // 3D pos x,y,z.
	void set_normals(std::vector<glm::vec3> norms);	 // 
	void set_uvs(std::vector<glm::vec2> uvs);		 // texture 2D coordinates.
	void set_indices(std::vector<unsigned short> indices);   // face indicies
};

#endif