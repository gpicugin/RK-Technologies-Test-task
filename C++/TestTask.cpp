// TestTask.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#define cimg_use_jpeg
#include "../CImg/CImg.h"
#include <string>
#include <sstream>
#define u_char unsigned char
using namespace cimg_library;


struct Pixel
{
    u_char *r;
    u_char *g;
    u_char *b;
};
void Luma(Pixel pixel, int value)
{
    u_char& r = *pixel.r;
    u_char& g = *pixel.g;
    u_char& b = *pixel.b;

    if (r + value > 255)
        r = 255;
    else if (r + value < 0)
        r = 0;
    else
        r += value;

    if (g + value > 255)
        g = 255;
    else if (g + value < 0)
        g = 0;
    else
        g += value;

    if (b + value > 255)
        b = 255;
    else if (b + value < 0)
        b = 0;
    else
        b += value;
}

int main() {
    std::string filename_src = "..\\lena_result\\lena.jpg";
    CImg<u_char> image(filename_src.c_str()), visu(500, 400, 1, 3, 0);
    const u_char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
    
    Pixel pixel;
    int width = image.width();
    int height = image.height();
    int value;
    std::cin >> value;

    CImg<u_char> image2 = image;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            pixel.r = image2.data(i, j, 0, 0);
            pixel.g = image2.data(i, j, 0, 1);
            pixel.b = image2.data(i, j, 0, 2);
            Luma(pixel, value);
        }
    }
    std::stringstream ss;
    ss << filename_src.erase(filename_src.size() - 4) << "_brightness_" << value << ".jpg";

    image2.save(ss.str().c_str());
    
    return 0;  
}

