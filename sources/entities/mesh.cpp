#include <mesh.hpp>

Mesh::Mesh() {

}

Mesh::Mesh(std::vector<glm::vec3>* verts, std::vector<glm::vec3>* norms,
	 	   std::vector<glm::vec2>* uvs,   std::vector<glm::vec3>* indicies) {

}

Mesh::~Mesh() {

	glDeleteBuffers(1, &vert_buff_id);
	glDeleteBuffers(1, &norm_buff_id);
	glDeleteBuffers(1, &uvs_buff_id);
	glDeleteBuffers(1, &indices_buff_id);
}

void Mesh::setup() {

	glGenVertexArrays(1, &vao); // generate a VAO.
	glGenBuffers(1, &vbo);		// generate a VBO.
}

void Mesh::set_vertices(std::vector<glm::vec3>* verts) {

	this->verts = verts;
}

void Mesh::set_normals(std::vector<glm::vec3>* norms) {

	this->norms = norms;
} 

void Mesh::set_uvs(std::vector<glm::vec2>* uvs) {

	this->uvs = uvs;
}

void Mesh::set_indicies(std::vector<unsigned short>* indicies) {

	this->indicies = indicies;
}