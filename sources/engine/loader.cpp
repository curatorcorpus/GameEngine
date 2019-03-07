#include <loader.hpp>

void Loader::load_obj(std::string name, Model* model) 
{
	std::string directory = Model_Path + name + Model_Suffix;
	std::cerr << "[DEBUG::LOADER] Loading " << directory << std::endl;

	Assimp::Importer importer;

	// Uses Assimp for reading obj file.
	const aiScene* scene = importer.ReadFile(directory.c_str(), 0);
	if(!scene) 
	{
		std::cerr << "[DEBUG::LOADER] Failed to load: " << importer.GetErrorString();
		return;
	}

	// Allocates memory for the number of meshes in model.
	//model->reserve_list(scene->mNumMeshes);
		
	// For each mesh, extra all norms, indicies, vertices, and uv coordinates.
	for(int i = 0; i < scene->mNumMeshes; i++)
	{
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

		for(int j = 0; j < ai_mesh->mNumVertices; j++)
		{

			aiVector3D pos = ai_mesh->mVertices[j];
			aiVector3D norm = ai_mesh->mNormals[j];
			
			verts.push_back(glm::vec3(pos.x, pos.y, pos.z));
			norms.push_back(glm::vec3(norm.x, norm.y, norm.z));
			
			if(ai_mesh->mTextureCoords[0] != nullptr) 
			{
				aiVector3D uv = ai_mesh->mTextureCoords[0][j];
				uvs.push_back(glm::vec2(uv.x, uv.y));
			}
		}

		for(int j = 0; j < ai_mesh->mNumFaces; j++) 
		{
			indices.push_back(ai_mesh->mFaces[j].mIndices[0]);
			indices.push_back(ai_mesh->mFaces[j].mIndices[1]);
			indices.push_back(ai_mesh->mFaces[j].mIndices[2]);
		}
		
		Mesh mesh;

		mesh.set_vertices(verts);
		mesh.set_normals(norms);
		mesh.set_uvs(uvs);
		mesh.set_indices(indices);

		model->add_mesh(mesh);
	}
	std::cerr << "[DEBUG::LOADER] Finished loading an obj file" << std::endl;
}

/*
	Method for loading PNG image files to be used as textures. 
	Using LibPNG manuals:
	http://www.libpng.org/pub/png/libpng-manual.txt
	http://www.libpng.org/pub/png/libpng-1.2.5-manual.html
 */
void Loader::load_PNG(texture_info* tex_info)
{
    unsigned int sig_read = 0;
    int color_type, interlace_type, bit_depth;

	png_structp png_ptr;
	png_infop 	info_ptr;

	std::string file_name;
	
	size_t prefix_pos = tex_info->name.find("../");
	size_t suffix_pos = tex_info->name.find(PNG_Suffix);

	// If no prefix or suffix filepath indicators. [Very hacky, but good for now]. 
	if(prefix_pos == std::string::npos && suffix_pos == std::string::npos)
	{
		file_name = Texture_Path + tex_info->name + PNG_Suffix;
	}
	else
	{
		file_name = tex_info->name;
	}

	std::cerr << "[LOADER::LOAD_PNG] Reading from: " << file_name << std::endl;

	FILE *fp;

	// Try open the image file - read bytes.
	fp = fopen(file_name.c_str(), "rb");
	if(fp == NULL) 
	{
		tex_info->is_loaded = false;
		return;
	}

	// Create and initialize the png_struct with the desired error handler
    // functions. If you want to use the default stderr and longjump method,
    // you can supply NULL for the last three parameters. We also supply the
    // the compiler header file version, so that we know if the application
    // was compiled with a compatible version of the library.
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL) 
    {
        fclose(fp);
		tex_info->is_loaded = false;
        return;
    }

    // Allocate/initialize the memory for the image information.
    info_ptr = png_create_info_struct(png_ptr);
    if(info_ptr == NULL) 
    {
    	fclose(fp);
    	png_destroy_read_struct(&png_ptr, NULL, NULL);
		tex_info->is_loaded = false;
    	return;
    }

    // Set error handling if you are using the setjmp/longjmp method (this is 
    // the normal method fo doing things with libpng). REQUIRED unless you set 
    // up your own error handlers in the png_create_read_struct() earlier.
    if(setjmp(png_jmpbuf(png_ptr))) 
    { 	// Free all of the memory assocaited with png_ptr and info_ptr.
    	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    	fclose(fp);
		tex_info->is_loaded = false;
    	return; // There was a problem reading the png file.
    }

    png_init_io(png_ptr, fp); 			  // Set up the output control if you are using standard C streams. 
    png_set_sig_bytes(png_ptr, sig_read); // If we have already read some of the signature.
 
    // If you have enough memory to read in the entire image at once, and
    // you need to specify only transforms that can be controlled
    // with one of the PNG_TRANSFORM_* bits (this presently excludes
    // dithering, filling, setting background, and doing gamma
    // adjustment), then you can read the entire image (including pixels)
    // into the info structure with this call.
    // PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING  forces 8 bit PNG_TRANSFORM_EXPAND forces to
    // expand a palette into RGB.
	// ADDING PNG_TRANSFORM_STRIP_ALPHA WORKS FOR GRASS TEXTURES WHY??? 
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16|PNG_TRANSFORM_PACKING|PNG_TRANSFORM_EXPAND|PNG_TRANSFORM_STRIP_ALPHA, NULL);
    png_get_IHDR(png_ptr, info_ptr, &tex_info->width, &tex_info->height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
 
   	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    tex_info->data = (unsigned char*) malloc(row_bytes * tex_info->height);
 
    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
 
    for (int i = 0; i < tex_info->height; i++) 
	{
        // note that png is ordered top to
        // bottom, but OpenGL expect it bottom to top
        // so the order or swapped
        memcpy(tex_info->data+(row_bytes * (tex_info->height-1-i)), row_pointers[i], row_bytes);
    }

    // Clean up after the read and free any memory allocated.
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    // Close file.
	fclose(fp);

	tex_info->is_loaded = true;
}