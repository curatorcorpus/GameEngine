#include <skybox.hpp>

Skybox::Skybox()
{
    this->cubemap = new CubeMap("cloudy_skies");
    this->cube = new Mesh(cubemesh);
    this->add_mesh(*cube);
}

Skybox::~Skybox()
{
    delete cube;
    delete cubemap;
}

void Skybox::setup(SkyboxShader* sky_shader, glm::mat4 proj_matrix) 
{
    std::cerr << "[SKYBOX::SETUP] Generating Skybox" << std::endl;

    this->cubemap->setup(sky_shader);

    this->sky_shader = sky_shader;
    this->sky_shader->bind();
    this->sky_shader->set_proj_matrix(proj_matrix);
    this->sky_shader->unbind();

    for(int i = 0; i < meshes.size(); i++) 
    {
        meshes[i].setup();
    }
}

void Skybox::render(Camera* camera)
{

    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
    glDepthMask(GL_FALSE);
    glm::mat4 view_mat = camera->get_view_mat();

    // prevent skybox front translating, follow the camera.
    view_mat[3][0] = 0.0f;
    view_mat[3][1] = 0.0f;
    view_mat[3][2] = 0.0f;

    this->sky_shader->bind();
    this->sky_shader->update_view_matrix(view_mat);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap->get_tex_id());

	for(int i = 0; i < meshes.size(); i++) 
	{
		meshes[i].render();
	}

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    //std::cerr << cubemap->get_tex_id() << std::endl;
    //cube->render();

    this->sky_shader->unbind();
    glDepthMask(GL_TRUE);
    glDisable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
}