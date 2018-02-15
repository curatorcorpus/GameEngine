#include <model_loader.hpp>

ModelLoader::ModelLoader() {

}

ModelLoader::~ModelLoader() {
}

Model* ModelLoader::load_obj(std::string name, const std::string& shader_name) {

	Model* model = new Model(shader_name);

	std::string directory = Model_Path + name + Model_Suffix;
	std::cerr << "[DEBUG::MODEL_LOADER_CPP] Loading " << directory << std::endl;

	Assimp::Importer importer;

	// Uses Assimp for reading obj file.
	const aiScene* scene = importer.ReadFile(directory.c_str(), 0);
	if(!scene) {
		std::cerr << "[DEBUG::MODEL_LOADER_CPP] Failed to load: " << importer.GetErrorString();

		return nullptr;
	}

	// Allocates memory for the number of meshes in model.
	model->reserve_list(scene->mNumMeshes);
	
	// For each mesh, extra all norms, indicies, vertices, and uv coordinates.
	for(int i = 0; i < scene->mNumMeshes; i++) {

		// outputs
		std::vector<glm::vec3> 		verts;
		std::vector<glm::vec2> 		uvs;
		std::vector<glm::vec3> 		norms;
		std::vector<unsigned short>	indices;

		aiMesh* ai_mesh = scene->mMeshes[i];

		verts.reserve(ai_mesh->mNumVertices); 	 // read mesh vertices
		uvs.reserve(ai_mesh->mNumVertices); 	 // read mesh texture coordinates
		verts.reserve(ai_mesh->mNumVertices); 	 // read mesh normals
		indices.reserve(3 * ai_mesh->mNumFaces); // read mesh face indices

		for(int j = 0; j < ai_mesh->mNumVertices; j++) {

			aiVector3D pos = ai_mesh->mVertices[j];
			aiVector3D norm = ai_mesh->mNormals[j];

			verts.push_back(glm::vec3(pos.x, pos.y, pos.z));
			norms.push_back(glm::vec3(norm.x, norm.y, norm.z));

			if(ai_mesh->mTextureCoords[0] != nullptr) {

				aiVector3D uv = ai_mesh->mTextureCoords[0][j];
				uvs.push_back(glm::vec2(uv.x, uv.y));
			}
		}

		for(int j = 0; j < ai_mesh->mNumFaces; j++) {

			indices.push_back(ai_mesh->mFaces[j].mIndices[0]);
			indices.push_back(ai_mesh->mFaces[j].mIndices[1]);
			indices.push_back(ai_mesh->mFaces[j].mIndices[2]);
		}
		
		Mesh* mesh = new Mesh();

		mesh->set_vertices(verts);
		mesh->set_normals(norms);
		mesh->set_uvs(uvs);
		mesh->set_indices(indices);

		model->add_mesh(mesh);
	}
	std::cerr << "[Debug::MODEL_LOADER_CPP] Finished loading an obj file" << std::endl;

	return model;
}