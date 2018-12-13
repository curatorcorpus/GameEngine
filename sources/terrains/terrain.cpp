#include <terrain.hpp>

Terrain::Terrain(std::string terrain_texture_name, std::string shader_name) : TexturedModel(terrain_texture_name, shader_name)
{

}

void Terrain::generate_terrains()
{
    std::vector<glm::vec3>      verts;
    std::vector<glm::vec3>      norms;
    std::vector<glm::vec2>      uvs;
    std::vector<unsigned short> indices;

    float y = 0.0;

    for(float x_idx = 0; x_idx < VERTICES_NO; x_idx++)
    {
        for(float z_idx = 0; z_idx < VERTICES_NO; z_idx++)
        {
            
        }
    }   

    //for()
    //{

    //}
}