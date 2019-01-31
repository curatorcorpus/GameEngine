#include <cubemap.hpp>

CubeMap::CubeMap(std::string name) 
{
    this->directory += name + "/";

    read_directory();
}

CubeMap::~CubeMap() {}

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
    }
    closedir(dir);
}