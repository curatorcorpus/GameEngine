#ifndef CUBEMAP_HPP_
#define CUBEMAP_HPP_

/*
    C Includes.
*/
#include <dirent.h>

/*
    C++ Includes.
*/
#include <iostream>
#include <string>
#include <vector>

/*
    Project Includes.
*/
#include <loader.hpp>
#include <skybox_shader.hpp>

class CubeMap {

private:
    // DATAFIELDS
    GLuint id;

    std::string directory = "../resources/textures/cubemaps/";
    std::vector<std::string> filenames;

    // OVERRIDE-ABLE METHODS


	// METHODS
    void load_cubemap(SkyboxShader* sky_shader);
    void read_directory();

    // GETTERS


    // SETTERS


public:

    // CONSTRUCTORS
    CubeMap(std::string name);

    // DECONSTRUCTOR
    ~CubeMap();

   	// OVERRIDE-ABLE METHODS


	// METHODS
    void setup(SkyboxShader* sky_shader);

    // GETTERS
    GLuint get_tex_id();

    // SETTERS

};

#endif