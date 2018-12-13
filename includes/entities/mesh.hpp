#ifndef MESH_HPP
#define MESH_HPP
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <vector>

#include <camera.hpp>
#include <transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/glm.hpp>

class Mesh : public Transform {

private:

	GLuint vao;

	GLuint vert_buff_id;
	GLuint norm_buff_id;
	GLuint uvs_buff_id;
	GLuint indices_buff_id;

	std::vector<glm::vec3> 	 	verts;
	std::vector<glm::vec3>	 	norms;
	std::vector<glm::vec2>		uvs;
	std::vector<unsigned short> indices;

	Shader* shader;

	void bind_shader();
	void unbind_shader();

public:

	Mesh();
	Mesh(std::vector<glm::vec3>* verts, std::vector<glm::vec3>* norm, 
		 std::vector<glm::vec2>* uvs,   std::vector<unsigned short>* indices);
	~Mesh();

	void set_vertices(std::vector<glm::vec3> verts); // 3D pos x,y,z.
	void set_normals(std::vector<glm::vec3> norms);	 // 
	void set_uvs(std::vector<glm::vec2> uvs);		 // texture 2D coordinates.
	void set_indices(std::vector<unsigned short> indices);   // face indicies.

	void set_shader(Shader* shader);

	void render(Camera* camera);
	void setup();
};

#endif