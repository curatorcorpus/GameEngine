#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <loader.hpp>
#include <mesh.hpp>
#include <model.hpp>
#include <shader.hpp>

class Terrain : public Model {

private:

    static constexpr float  TILE_MULTIPILER = 40.0f; // Used for multiplying normalized uv coordinates. OpenGL automatically tiles texture.
    static const int        SIZE = 800;
    static const int        VERTICES_NO = 128;

    Loader::texture_info tex_info;

    void generate_terrain();
    void load_texture(Loader::texture_info& tex_info);

public: 

    Terrain(std::string texture_name);
    ~Terrain();

    void render(Camera* camera);
};

#endif