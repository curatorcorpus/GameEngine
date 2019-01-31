#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <camera.hpp>
#include <loader.hpp>
#include <model.hpp>
#include <object_shader.hpp>

class Object : public Model {

private:
	static constexpr const char* const Texture_Path = "../resources/textures/";
	static constexpr const char* const PNG_Suffix 	= ".png";

    Loader::texture_info tex_info;

	ObjectShader* o_shader;

	void load_texture();

public:
	Object(std::string name, std::string texture_name);
	~Object();

	void setup(ObjectShader* o_shader);
	void render(Camera* camera);

	void set_meshes();
};

#endif