#include <terrain.hpp>

Terrain::Terrain(std::string terrain_texture_name) : TexturedModel(terrain_texture_name, "terrain")
{
    generate_terrain();
}

Terrain::~Terrain() {}

/**
    PRIVATE METHODS    
**/

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

    for(int z_idx = 0; z_idx < VERTICES_NO; z_idx++)
    {
        for(int x_idx = 0; x_idx < VERTICES_NO; x_idx++)
        {
            // generate vertex
            float x = (float) x_idx / ((float) VERTICES_NO - 1) * SIZE;
            float z = (float) z_idx / ((float) VERTICES_NO - 1) * SIZE;

            // generate norm (flat terrain)
            glm::vec3 norm(0.0f, 1.0f, 0.0f);

            // generate uv
            float u = (float) x_idx / ((float) VERTICES_NO - 1);
            float v = (float) z_idx / ((float) VERTICES_NO - 1);

            glm::vec3 vert(x, y, z);
            glm::vec2 uv(u, v);

            // add mesh components
            verts.push_back(verts);
            norms.push_back(norm);
            uvs.push_back(uv);

            std::cout << x << " " << y << " " << z << " " << u << " " << v << std::endl; 
        }
    }   

    for(int z_idx = 0; z_idx < VERTICES_NO - 1; z_idx++)
    {
        for(int x_idx = 0; x_idx < VERTICES_NO - 1; x_idx++)
        {
            // generate indices for one terrain chunk
            int top_left  = z_idx * VERTICES_NO + x_idx;
            int top_right = top_left + 1;
            int bottom_left = ((z_idx + 1) * VERTICES_NO) + x_idx;
            int bottom_right = bottom_left + 1;

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

    Mesh terrain_mesh(&verts, &norm, &uvs, &indices);
    add_mesh(&terrain_mesh);
}