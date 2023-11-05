#include <iostream>
#include <fstream>

using namespace std;

void addHeader(ofstream &file,string type, int width, int height){
    file << type << endl;
    file << width << " " << height << endl;
    file << 255 << endl;
}

void createTexture(ofstream &file, int width, int height){
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            file << x << " " << y << " " << 0 << "   ";
        }
        file << endl;
    }
    
}

int main(){

    ofstream uvImage;
    uvImage.open("UVcoordinates.ppm");
    
    addHeader(uvImage, "P3", 256, 256);
    createTexture(uvImage, 256, 256);


    uvImage.close();
    return 0;
}