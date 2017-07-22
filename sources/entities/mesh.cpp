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
	glBindBuffer(GL_ARRAY_BUFFER, vert_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verts->size()    * sizeof(verts),    verts,    GL_STATIC_DRAW);
/*
	glGenBuffers(1, &norm_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, norm_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, norms->size()    * sizeof(norms),    norms,    GL_STATIC_DRAW);
	

	glGenBuffers(1, &uvs_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, uvs_buff_id);	
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvs->size() 	   * sizeof(uvs),      uvs, 	 GL_STATIC_DRAW);

	glGenBuffers(1, &indices_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, indices_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies->size() * sizeof(indicies), indicies, GL_STATIC_DRAW);
*/
	// enable VAO attributes
	glEnableVertexAttribArray(0); // verts
/*	glEnableVertexAttribArray(1); // norms
	glEnableVertexAttribArray(2); // uvs
	glEnableVertexAttribArray(3); // indicies

	// specifies how the vertex buffer object data should be handled.
	glVertexAttribPointer( // verts
							0,        // attribute
                            3,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );

	glVertexAttribPointer( // norms
							1,        // attribute
                            3,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );

	glVertexAttribPointer( // uvs
							2,        // attribute
                            2,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );

	glVertexAttribPointer( // indicies
							3,                 // attribute
                            3,                 // size
                            GL_UNSIGNED_SHORT, // type
                            GL_FALSE,          // normalized?
                            0,                 // stride
                            (void*)0           // array buffer offset
                        );*/

	glBindVertexArray(0);
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

void Mesh::render() {

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indicies->size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}