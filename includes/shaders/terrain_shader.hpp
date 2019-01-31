#ifndef TERRAIN_SHADER_HPP
#define TERRAIN_SHADER_HPP

#include <iostream>

#include <shader.hpp>
#include <terrain_shader.hpp>

class TerrainShader : public Shader {

private:
    
    GLuint tex_uniloc;

    void setup(std::string& vert_path, std::string& frag_path);

    void set_uniform_loc();

public:

    TerrainShader();
    ~TerrainShader();

    GLuint get_texuniloc();
};

#endif