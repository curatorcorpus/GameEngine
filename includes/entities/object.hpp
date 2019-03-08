#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <camera.hpp>
#include <cubemap.hpp>
#include <loader.hpp>
#include <model.hpp>
#include <object_shader.hpp>

class Object : public Model {

private:
	// CONSTANTS
	static constexpr const char* const Texture_Path = "../resources/textures/";
	static constexpr const char* const PNG_Suffix 	= ".png";

	// DATAFIELDS
    Loader::texture_info tex_info;
	ObjectShader* o_shader;

	// METHODS
	void load_texture();

public:
	// CONSTRUTORS
	Object(std::string name, std::string texture_name);

	// DESTRUCTOR
	~Object();

	// METHODS
	void setup(ObjectShader* o_shader);
	void render(Camera* camera, glm::mat4& mvp);

	// GETTERS


	// SETTERS
};

#endif