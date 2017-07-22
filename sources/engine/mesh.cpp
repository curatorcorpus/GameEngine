#include <mesh.hpp>

Mesh::Mesh() {

}

Mesh::Mesh(std::vector<glm::vec3>* verts, std::vector<glm::vec3>* norms,
	 	   std::vector<glm::vec2>* uvs,   std::vector<unsigned short>* indices) {

}

Mesh::~Mesh() {

	glDeleteBuffers(1, &vert_buff_id);
	glDeleteBuffers(1, &norm_buff_id);
	glDeleteBuffers(1, &uvs_buff_id);
	glDeleteBuffers(1, &indices_buff_id);

	glDeleteVertexArrays(1, &vao);
}

void Mesh::setup() {

	// create VAO.
	glGenVertexArrays(1, &vao); // generate a VAO.
	glBindVertexArray(vao);	    // prepare vao, any subsequent vertex pointer calls will be stored in VAO.

	// create and obtain reference to buffer objects.
	glGenBuffers(1, &vert_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, vert_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer( // verts
							0,        // attribute
                            3,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &norm_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, norm_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, norms.size() * sizeof(glm::vec3), &norms[0], GL_STATIC_DRAW);
	glVertexAttribPointer( // norms
							1,        // attribute
                            3,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &uvs_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, uvs_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	glVertexAttribPointer( // uvs
							2,        // attribute
                            2,        // size
                            GL_FLOAT, // type
                            GL_FALSE, // normalized?
                            0,        // stride
                            (void*)0  // array buffer offset
                        );
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indices_buff_id);
	glBindBuffer(GL_ARRAY_BUFFER, indices_buff_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0], GL_STATIC_DRAW);
	glVertexAttribPointer( // indices
							3,                 // attribute
                            3,                 // size
                            GL_UNSIGNED_SHORT, // type
                            GL_FALSE,          // normalized?
                            0,                 // stride
                            (void*)0           // array buffer offset
                        );
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// enable VAO attributes
	// specifies how the vertex buffer object data should be handled.

	glBindVertexArray(0);
}

void Mesh::set_vertices(std::vector<glm::vec3> verts) {

	this->verts.clear();
	this->verts.resize(verts.size());

	std::copy(verts.begin(), verts.end(), this->verts.begin());
}

void Mesh::set_normals(std::vector<glm::vec3> norms) {

	this->norms.clear();
	this->norms.resize(norms.size());

	std::copy(norms.begin(), norms.end(), this->norms.begin());
} 

void Mesh::set_uvs(std::vector<glm::vec2> uvs) {

	this->uvs.clear();
	this->uvs.resize(uvs.size());

	std::copy(uvs.begin(), uvs.end(), this->uvs.begin());
}

void Mesh::set_indices(std::vector<unsigned short> indices) {

	this->indices.clear();
	this->indices.resize(indices.size());

	std::copy(indices.begin(), indices.end(), this->indices.begin());
}

void Mesh::render(Camera* camera) {

	bind_shader();

	glm::mat4 model = this->get_transform();
	glm::mat4 mvp   = model * camera->get_view_proj_mat();

	shader->update_mvp(mvp);

	glBindVertexArray(vao);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glDrawElements(GL_TRIANGLES, verts.size(), GL_FLOAT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);

	glBindVertexArray(0);
}