#include <textured_model.hpp>

TexturedModel::TexturedModel(std::string texture_name, std::string shader_name) : Model(shader_name) {

	this->texture_name = texture_name;
}

TexturedModel::~TexturedModel() {

	free(texture_image);
}

void TexturedModel::setup() {

	glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id); 
    // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	bool isLoaded = load_texture_image(texture_name);
	if(isLoaded) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->texture_image);
        glGenerateMipmap(GL_TEXTURE_2D);
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP]" << " Texture " << texture_name << " loaded!" << std::endl;
	}
	else 
	{
		std::cerr << "[DEBUG::MASTER_RENDERER_CPP]" << " Texture " << texture_name << " failed to load!" << std::endl;
		return;
	}

	// Set uniform variable name for shader program.
	glUniform1i(glGetUniformLocation(shader->get_prog_id(), "texture2D"), 0);
}

void TexturedModel::render(Camera* camera) {

	glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);

	for(int i = 0; i < size; i++) 
	{
		meshes[i]->render(camera);
	}
}

bool TexturedModel::load_texture_image(std::string name) {

    unsigned int sig_read = 0;
    int color_type, interlace_type, bit_depth;

	png_structp png_ptr;
	png_infop 	info_ptr;

	std::string file_name = Texture_Path + name + PNG_Suffix;

	FILE *fp;

	// Try open the image file - read bytes.
	fp = fopen(file_name.c_str(), "rb");
	if(fp == NULL) 
	{
		return false;
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
        return false;
    }

    // Allocate/initialize the memory for the image information.
    info_ptr = png_create_info_struct(png_ptr);
    if(info_ptr == NULL) 
    {
    	fclose(fp);
    	png_destroy_read_struct(&png_ptr, NULL, NULL);
    	return false;
    }

    // Set error handling if you are using the setjmp/longjmp method (this is 
    // the normal method fo doing things with libpng). REQUIRED unless you set 
    // up your own error handlers in the png_create_read_struct() earlier.
    if(setjmp(png_jmpbuf(png_ptr))) 
    { 	// Free all of the memory assocaited with png_ptr and info_ptr.
    	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    	fclose(fp);
    	return false; // There was a problem reading the png file.
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
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16|PNG_TRANSFORM_PACKING|PNG_TRANSFORM_EXPAND, NULL);
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
 
   	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    texture_image = (unsigned char*) malloc(row_bytes * height);
 
    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
 
    for (int i = 0; i < height; i++) 
    {
        // note that png is ordered top to
        // bottom, but OpenGL expect it bottom to top
        // so the order or swapped
        memcpy(texture_image+(row_bytes * (height-1-i)), row_pointers[i], row_bytes);
    }

    // Clean up after the read and free any memory allocated.
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    // Close file.
	fclose(fp);

	return true;
}

