#ifndef SKYBOX_SHADER_HPP_
#define SKYBOX_SHADER_HPP_

/*
    C Includes.
*/


/*
    C++ Includes.
*/
#include <iostream>

/*
    Project Includes.
*/
#include <shader.hpp>

class SkyboxShader : public Shader {

private:
    // DATAFIELDS
    GLuint tex_uniloc;

    // OVERRIDE-ABLE METHODS
    void setup(std::string& vert_path, std::string& frag_path);

	// METHODS


    // GETTERS


    // SETTERS
    void set_uniform_loc();

public:

    // CONSTRUCTORS
    SkyboxShader();
    ~SkyboxShader();

   	// OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS
    GLuint get_texuniloc();

    // SETTERS
    
};

#endif