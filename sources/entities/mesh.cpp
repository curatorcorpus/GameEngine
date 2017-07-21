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

	// create VAO.
	glGenVertexArrays(1, &vao); // generate a VAO.
	glBindVertexArray(vao);	    // prepare vao, any subsequent vertex pointer calls will be stored in VAO.
	
	// create and obtain reference to buffer objects.
	glGenBuffers(1, &vert_buff_id);
	glGenBuffers(1, &norm_buff_id);
	glGenBuffers(1, &uvs_buff_id);
	glGenBuffers(1, &indices_buff_id);

	// binds buffer object to buffer type.
	glBindBuffer(GL_ARRAY_BUFFER, vert_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, norm_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, uvs_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, indices_buff_id);

	// allocate memory and load related data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verts->size()    * sizeof(verts),    verts,    GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, norms->size()    * sizeof(norms),    norms,    GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvs->size() 	   * sizeof(uvs),      uvs, 	 GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies->size() * sizeof(indicies), indicies, GL_STATIC_DRAW);
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