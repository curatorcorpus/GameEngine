#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>

#include <camera.hpp>
#include <loader.hpp>
#include <model.hpp>
#include <terrain_shader.hpp>

class Terrain : public Model {

private:

    static constexpr float  TILE_MULTIPILER = 80.0f; // Used for multiplying normalized uv coordinates. OpenGL automatically tiles texture.
    static const int        SIZE = 800;
    static const int        VERTICES_NO = 128;

    Loader::texture_info tex_info;
    TerrainShader* t_shader;

    void generate_terrain();
    void load_texture();

public: 

    Terrain(std::string texture_name);
    ~Terrain();

    void render(Camera* camera);
    void setup(TerrainShader* shader);

    void set_meshes();
};

#endif