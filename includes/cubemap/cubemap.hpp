#ifndef CUBEMAP_HPP_
#define CUBEMAP_HPP_

#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>

class CubeMap {

private:
    // DATAFIELDS
    std::string directory = "../resources/textures/cubemaps/";
    std::vector<std::string> filenames;

    // OVERRIDE-ABLE METHODS


	// METHODS
    void read_directory();

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