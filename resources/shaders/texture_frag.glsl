#version 330 core

// These mesh positions and normals are in world space.
in vec3 pos;
in vec3 norm;
in vec2 uv;

out vec4 color;

uniform sampler2D _texture;

const vec3 ambient_color = vec3(0.5f,0.5f,0.5f);
const vec3 ambient_light = vec3(0.2f,0.2f,0.2f);

void main() 
{
	vec3 texture_color = texture(_texture, uv).xyz;	

	// Normalize lighting components.
	vec3 N = normalize(norm);

	vec3 ambient_compo = ambient_light * ambient_color * texture_color;
	vec3 blinn_phong = ambient_compo;

	color = vec4(blinn_phong, 1.0f);
};