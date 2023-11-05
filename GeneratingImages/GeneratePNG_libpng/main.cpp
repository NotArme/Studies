/*

References:
http://www.labbookpages.co.uk/software/imgProc/libPNG.html
https://stackoverflow.com/questions/39815996/how-should-i-use-libpng-library-to-convert-rgba-bitmap-into-png-and-png-back-to

*/


#include <iostream>

#include "png.h"

using namespace std;

void writePng(int width, int height){
    FILE *fp;
    png_structp png_ptr;
    png_infop info_ptr;
    png_bytep row = NULL;
    png_colorp palette;

    fp = fopen("testFile.png", "wb");
    if (fp == NULL){
        cout << "something went wrong 1 lol" << endl;
        return;
    }

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL){
        fclose(fp);
        cout << "something went wrong 2 lol" << endl;
        return;
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        fclose(fp);
        png_destroy_write_struct(&png_ptr, NULL);
        cout << "something went wrong 3 lol" << endl;
        return;
    }

    cout << "test" << endl;
    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, width, height,
         8, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
         PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    //allocate 4 bytes per pixel to acommodate RGBA data per pixel
    row = (png_bytep) malloc(4 * width * sizeof(png_byte));

    int x, y;
    for ( y = 0; y < height; y++)
    {
        for ( x = 0; x < width; x++)
        {
            row[x*4] = x;
            row[x*4 + 1] = y;
            row[x*4 + 2] = 0;
            row[x*4 + 3] = 255;
        }
        png_write_row(png_ptr, row);
    }
    
    png_write_end(png_ptr, info_ptr);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}

int main(){

    png_image image;

    writePng(256, 256);

    return 0;
}