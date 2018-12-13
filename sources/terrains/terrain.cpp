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

    int offset = 0;
    float y = 0.0f;

    for(int z_idx = 0; z_idx < VERTICES_NO; z_idx++)
    {
        for(int x_idx = 0; x_idx < VERTICES_NO; x_idx++)
        {
            // generate vertices
            float x = (float) _idx / ((float) VERTICES_NO - 1) * SIZE;

            //glm::vec3 vert();
        }
    }   

    //for()
    //{

    //}
}