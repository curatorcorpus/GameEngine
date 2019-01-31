#include <terrain.hpp>

Terrain::Terrain(std::string texture_name)
{
    this->tex_info.name = texture_name;
}

Terrain::~Terrain() 
{
    glDeleteTextures(1, &tex_info.id);
}

/*=================
    PRIVATE METHODS    
/==================

/*
    Method for generating a flat terrain, from ThinMatrix:
    https://www.youtube.com/watch?v=yNYwZMmgTJk&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP&index=14
*/
void Terrain::generate_terrain()
{
    std::vector<glm::vec3>      verts;
    std::vector<glm::vec3>      norms;
    std::vector<glm::vec2>      uvs;
    std::vector<unsigned short> indices;

    float y = 0.0f;

    for(int z_idx = -(VERTICES_NO/2); z_idx < (VERTICES_NO/2); z_idx++)
    {
        for(int x_idx = -(VERTICES_NO/2); x_idx < (VERTICES_NO/2); x_idx++)
        {
            // generate vertex
            float x = (float) x_idx / ((float) (VERTICES_NO/2) - 1) * SIZE;
            float z = (float) z_idx / ((float) (VERTICES_NO/2) - 1) * SIZE;
           // y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10)); // pseudo random terrain genration [basic]
            // generate norm (flat terrain)
            glm::vec3 norm(0.0f, 1.0f, 0.0f);

            // generate uv
            float u = ((float) x_idx / ((float) VERTICES_NO - 1)) * TILE_MULTIPILER;
            float v = ((float) z_idx / ((float) VERTICES_NO - 1)) * TILE_MULTIPILER;

            glm::vec3 vert(x, y, z);
            glm::vec2 uv(u, v);
            //std::cout << u << " " << v << std::endl; 
            // add mesh components
            verts.push_back(vert);
            norms.push_back(norm);
            uvs.push_back(uv);

           //std::cout << x << " " << y << " " << z << " " << u << " " << v << std::endl; 
        }
    }   

    for(unsigned short z_idx = 0; z_idx < VERTICES_NO - 1; z_idx++)
    {
        for(unsigned short x_idx = 0; x_idx < VERTICES_NO - 1; x_idx++)
        {
            // generate indices for one terrain chunk
            unsigned short top_left  = z_idx * VERTICES_NO + x_idx;
            unsigned short top_right = top_left + 1;
            unsigned short bottom_left = ((z_idx + 1) * VERTICES_NO) + x_idx;
            unsigned short bottom_right = bottom_left + 1;

            // first triangle that makes up the square
            indices.push_back(top_left);
            indices.push_back(bottom_left);
            indices.push_back(top_right);

            // second triangle that makes up the square
            indices.push_back(top_right);
            indices.push_back(bottom_left);
            indices.push_back(bottom_right);
        }
    }
    Mesh terrain_mesh(verts, norms, uvs, indices);
   //             std::cout << "wtf" << terrain_mesh.get_verts_size() << std::endl;
    this->add_mesh(terrain_mesh);
}

void Terrain::load_texture()
{
	glGenTextures(1, &tex_info.id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex_info.id);

    // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Loader::load_PNG(&tex_info);
	if(tex_info.is_loaded) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_info.width, tex_info.height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_info.data);
        glGenerateMipmap(GL_TEXTURE_2D);
		std::cerr << "[DEBUG::TERRAIN]" << " Texture " << tex_info.name << " loaded!" << std::endl;
	}
	else 
	{
		std::cerr << "[DEBUG::TERRAIN]" << " Texture " << tex_info.name << " failed to load!" << std::endl;
		return;
	}

	// Set uniform variable name for shader program.
    glUniform1i(this->t_shader->get_texuniloc(), GL_TEXTURE0); // gets uniform location in shader to update texture values. 

    // unbind
    glBindTexture(GL_TEXTURE_2D, 0);

    // free texture in memory. 
    free(tex_info.data);
}

void Terrain::render(Camera* camera)
{
	this->t_shader->bind(); // could be bound in master renderer for terrains.

    // activate binded texture.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex_info.id);

    // obtain current MVP and model transform.
	//glm::mat4 model = this->get_transform();
	glm::mat4 mvp = camera->get_view_proj_mat();// * model;

    // update MVP and camera pos in bound shader.
	this->t_shader->update_mvp(mvp);
	this->t_shader->update_cam_pos(camera->get_pos());

	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render();
	}

    glBindTexture(GL_TEXTURE_2D, 0);

	this->t_shader->unbind();
}

void Terrain::set_meshes() 
{
	for(int i = 0; i < meshes.size(); i++) 
	{	
		std::cerr << "[Terrain::SETUP_MESHES] " << this->t_shader->get_prog_id() << std::endl;
		meshes[i].setup();
	}
}

/*=================
    PRIVATE METHODS    
/==================

/*

*/
void Terrain::setup(TerrainShader* t_shader)
{
    this->t_shader = t_shader;

    generate_terrain();
    load_texture();
}