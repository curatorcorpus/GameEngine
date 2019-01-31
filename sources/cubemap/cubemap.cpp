#include <cubemap.hpp>

CubeMap::CubeMap(std::string name) 
{
    this->directory += name + "/";

    setup();
}

CubeMap::~CubeMap() 
{
 /*   if(filenames.size() > 0) 
    {   
        filenames.clear();
    }*/
    glDeleteTextures(1, &this->id);
}

/*

*/
void CubeMap::setup()
{
    read_directory();
    load_cubemap();
}

/*

*/
void CubeMap::load_cubemap()
{
    glGenTextures(1, &this->id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->id);

    int size = filenames.size();
    for(int i = 0; i < size; i++) 
    {
        Loader::texture_info tex_info;   
        tex_info.name = directory + filenames[i];

        Loader::load_PNG(&tex_info);
        if(tex_info.is_loaded) 
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, tex_info.width, tex_info.height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_info.data);
            std::cerr << "[CUBEMAP:LOAD_CUBEMAP]" << " Texture " << tex_info.name << " loaded!" << std::endl;
        }
        else 
        {
            std::cerr << "[CUBEMAP:LOAD_CUBEMAP]" << " Texture " << tex_info.name << " failed to load!" << std::endl;
            return;
        }
        free(tex_info.data);
    }
    
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

/*
    Method used for reading all files in a directory. Uses the
    dirent.h include files from C. Apparently Windows version exists.
    Reads only png image files for now.
*/
void CubeMap::read_directory()
{
    struct dirent* ent; 
    DIR* dir = opendir(directory.c_str());

    if(dir != NULL)
    {
        std::cerr << "[CUBEMAP::READ_DIR] Reading cubemap directory: " << directory << std::endl;
        while((ent = readdir(dir)) != NULL)
        {
            std::string filename(ent->d_name);
            if(filename.find(".png") != std::string::npos) 
            {
                std::cerr << "[CUBEMAP::READ_DIR] " << filename << std::endl;
                filenames.push_back(filename);
            }
        }

        // Check how many files were read.
        if(filenames.size() == 0) 
            std::cerr << "[CUBEMAP::READ_DIR] No cubemap textures found" << std::endl;
        else
            std::cerr << "[CUBEMAP::READ_DIR] Found " << filenames.size() << " cubemap textures" << std::endl;                 
    }
    else
    {
        std::cerr << "[CUBEMAP::READ_DIR] FAILED LOADING DIRECTORY!" << std::endl;
        return;
    }
    closedir(dir);
}