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

class CubeMap {

private:
    // DATAFIELDS
    GLuint id;

    std::string directory = "../resources/textures/cubemaps/";
    std::vector<std::string> filenames;

    // OVERRIDE-ABLE METHODS


	// METHODS
    void load_cubemap();
    void read_directory();
    void setup();

    // GETTERS


    // SETTERS


public:

    // CONSTRUCTORS
    CubeMap(std::string name);
    ~CubeMap();

   	// OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS


    // SETTERS

};

#endif