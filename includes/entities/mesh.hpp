#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>
#include <vector>

#include <object.hpp>

#include <glm/glm.hpp>

class Mesh : public Object {

private:

	GLuint vao;

	GLuint vert_buff_id;
	GLuint norm_buff_id;
	GLuint uvs_buff_id;
	GLuint indices_buff_id;

	std::vector<glm::vec3>* 	 verts;
	std::vector<glm::vec3>* 	 norms;
	std::vector<glm::vec2>*		 uvs;
	std::vector<unsigned short>* indicies;

	void setup();

public:

	Mesh();
	Mesh(std::vector<glm::vec3>* verts, std::vector<glm::vec3>* norm, 
		 std::vector<glm::vec2>* uvs,   std::vector<glm::vec3>* indicies);
	~Mesh();

	void set_vertices(std::vector<glm::vec3>* verts); // 3D pos x,y,z.
	void set_normals(std::vector<glm::vec3>* norms);	 // 
	void set_uvs(std::vector<glm::vec2>* uvs);		 // texture 2D coordinates.
	void set_indicies(std::vector<unsigned short>* indicies);   // face indicies.

};

#endif