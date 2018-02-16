#include <textured_model.hpp>

TexturedModel::TexturedModel(std::string texture_name, std::string shader_name) : Model(shader_name) {

	this->texture_name = texture_name;
}

TexturedModel::~TexturedModel() {

	free(texture_image);
}

bool TexturedModel::load_texture_image(std::string name) {

    unsigned int sig_read = 0;
    int color_type, interlace_type;

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
 
    int bit_depth;
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

