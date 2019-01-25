#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <mesh.hpp>
#include <textured_model.hpp>

class Terrain : public TexturedModel {

private:

    static constexpr float  TILE_MULTIPILER = 40.0f; // Used for multiplying normalized uv coordinates. OpenGL automatically tiles texture.
    static const int        SIZE = 800;
    static const int        VERTICES_NO = 128;

    void generate_terrain();

public: 

    Terrain(std::string texture_name);
    ~Terrain();
};

#endif