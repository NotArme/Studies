/*

References:
https://github.com/lvandeve/lodepng/blob/master/examples/example_encode.cpp

*/


#include <iostream>

#include "lodepng.h"

using namespace std;

void writePng(unsigned int width, unsigned int height){

    unsigned char *imageData;
    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    imageData = (unsigned char *) malloc(width * height * 4);

    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            imageData[4 * width * y + 4 * x + 0] = x;
            imageData[4 * width * y + 4 * x + 1] = y;
            imageData[4 * width * y + 4 * x + 2] = 0;
            imageData[4 * width * y + 4 * x + 3] = 255;
        }
        
    }

    lodepng_encode_file("testFile.png", imageData, width, height, LodePNGColorType::LCT_RGBA, 8);

    delete[] imageData;

}

int main(){

    writePng(256, 256);

    return 0;
}