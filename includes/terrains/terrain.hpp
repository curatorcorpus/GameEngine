#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <model.hpp>
#include <mesh.hpp>

class Terrain : public Model {

private:

    Mesh terrain_mesh;

public: 

    void generate_terrains();
};

#endif