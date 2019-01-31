#ifndef IMG_WRITER_HPP
#define IMG_WRITER_HPP

#include <iostream>
#include <png.h>

class ImgWriter {

public:
    static void save_png(std::string file_name, int w, int h, uint8_t *pixels);

};

#endif