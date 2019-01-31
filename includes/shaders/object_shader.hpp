#ifndef OBJECT_SHADER_HPP_
#define OBJECT_SHADER_HPP_

#include <shader.hpp>

class ObjectShader : public Shader {

private:

    // DATAFIELDS
    GLuint tex_uniloc;

    // OVERRIDE-ABLE METHODS


	// METHODS
    void setup(std::string& vert_path, std::string& frag_path);

    // GETTERS


    // SETTERS
    void set_uniform_loc();

public:

    // CONSTRUCTORS
    ObjectShader();
    ~ObjectShader();

   	// OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS
    GLuint get_texuniloc();    

    // SETTERS
};

#endif