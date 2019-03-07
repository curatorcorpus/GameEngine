#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>

#include <camera.hpp>
#include <loader.hpp>
#include <model.hpp>
#include <terrain_shader.hpp>

class Terrain : public Model {

private:

    // CONSTANTS
    static constexpr float  TILE_MULTIPILER = 200.0f; // Used for multiplying normalized uv coordinates. OpenGL automatically tiles texture.
    static const int        SIZE = 800;
    static const int        VERTICES_NO = 128;

    // DATAFIELDS
    Loader::texture_info tex_info;
    TerrainShader* t_shader;

    // METHODS

    void generate_terrain();
    void load_texture();

public: 
    // CONSTRUCTORS
    Terrain(std::string texture_name);

    // DECONSTRUCTORS
    ~Terrain();

    // METHODS
    void render(Camera* camera);
    void setup(TerrainShader* shader);

    // GETTERS


    // SETTERS

    void set_meshes();
};

#endif