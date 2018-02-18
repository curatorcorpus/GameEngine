#version 330 core

// These mesh positions and normals are in world space.
in vec3 norm;
in vec2 uv;

in vec3 light_dir;
in vec3 eye_dir;

out vec4 color;

uniform sampler2D _texture;
uniform vec3 cam_pos;

const vec3 ambient_color  = vec3(0.5f,0.5f,0.3f);
const vec3 ambient_light  = vec3(0.3f,0.3f,0.3f);

const vec3 diffuse_color  = vec3(1.0f,1.0f,1.0f);
const vec3 diffuse_light  = vec3(1.0f,1.0f,1.0f);

const vec3 specular_color = vec3(0.9f,0.8f,0.7f);
const vec3 specular_light = vec3(0.8f,0.8f,0.8f);

const float shininess = 128.0f;

void main() 
{
	vec3 texture_color = texture(_texture, uv).xyz;	

	// Normalize lighting components.
	vec3 N = normalize(norm);
	vec3 L = normalize(light_dir);
	vec3 E = normalize(eye_dir);

	vec3 half_way = normalize(L + E);

	float theta = clamp(dot(N,L), 0.0f, 1.0f);
	float cos_alpha = clamp(dot(N,half_way), 0.0f, 1.0f);

	vec3 ambient_compo  = ambient_light  * ambient_color  * texture_color;
	vec3 diffuse_compo  = diffuse_light  * diffuse_color  * texture_color * theta;
	vec3 specular_compo = specular_light * specular_color * pow(cos_alpha, shininess);

	vec3 blinn_phong = ambient_compo+diffuse_compo+specular_compo;

	color = vec4(blinn_phong, 1.0f);
};