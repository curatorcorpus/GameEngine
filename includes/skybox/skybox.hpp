#ifndef Skybox_HPP_
#define Skybox_HPP_

/*
    C Includes.
*/


/*
    C++ Includes.
*/
#include <iostream>
#include <vector>

/*
    Project Includes.
*/
#include <camera.hpp>
#include <cubemap.hpp>
#include <mesh.hpp>
#include <skybox_shader.hpp>

class Skybox : public Model {

private:
    // DATAFIELDS
    static constexpr float SIZE = 500.0f;    

    std::vector<glm::vec3> cubemesh {
		// FRONT        
	    glm::vec3(-SIZE,  SIZE, -SIZE),
	    glm::vec3(-SIZE, -SIZE, -SIZE),
	    glm::vec3(SIZE, -SIZE, -SIZE),
	    glm::vec3(SIZE, -SIZE, -SIZE),
	    glm::vec3(SIZE,  SIZE, -SIZE),
	    glm::vec3(-SIZE,  SIZE, -SIZE),

		// LEFT
	    glm::vec3(-SIZE, -SIZE,  SIZE),
	    glm::vec3(-SIZE, -SIZE, -SIZE),
	    glm::vec3(-SIZE,  SIZE, -SIZE),
	    glm::vec3(-SIZE,  SIZE, -SIZE),
	    glm::vec3(-SIZE,  SIZE,  SIZE),
	    glm::vec3(-SIZE, -SIZE,  SIZE),

		// RIGHT
	    glm::vec3(SIZE, -SIZE, -SIZE),
	    glm::vec3(SIZE, -SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE, -SIZE),
	    glm::vec3(SIZE, -SIZE, -SIZE),

		// BACK 
	    glm::vec3(-SIZE, -SIZE,  SIZE),
	    glm::vec3(-SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE, -SIZE,  SIZE),
	    glm::vec3(-SIZE, -SIZE,  SIZE),

		// TOP
	    glm::vec3(-SIZE,  SIZE, -SIZE),
	    glm::vec3(SIZE,  SIZE, -SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(SIZE,  SIZE,  SIZE),
	    glm::vec3(-SIZE,  SIZE,  SIZE),
        glm::vec3(-SIZE,  SIZE, -SIZE),

		// BOTTOM
	    glm::vec3(-SIZE, -SIZE, -SIZE),
	    glm::vec3(-SIZE, -SIZE,  SIZE),
	    glm::vec3(SIZE, -SIZE, -SIZE),
	    glm::vec3(SIZE, -SIZE, -SIZE),
	    glm::vec3(-SIZE, -SIZE,  SIZE),
	    glm::vec3(SIZE, -SIZE,  SIZE)
	};

    GLuint vao_id;
    GLuint vert_buff_id;

    Mesh* cube;
    CubeMap*      cubemap;
    SkyboxShader* sky_shader;

    // OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS


    // SETTERS


public:

    // CONSTRUCTORS
    Skybox();

	// DECONSTRUCTOR
    ~Skybox();

   	// OVERRIDE-ABLE METHODS


	// METHODS
    void setup(SkyboxShader* sky_shader, glm::mat4 proj_matrix);
    void render(Camera* camerea);

    // GETTERS


    // SETTERS

};

#endif