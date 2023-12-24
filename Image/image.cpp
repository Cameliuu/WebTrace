#include <iostream>
#include "image.h"



Image::Image(){}

Image::~Image()
{
    if(texture != NULL)
        SDL_DestroyTexture(texture);
}
Uint32 Image::GetLinearPosition(int x, int y) {
    return (y*width)+x;
}
void Image::SetPixel(int x, int y, Color color) {
    Uint32 pos = GetLinearPosition(x,y);
;
    pixels.at(pos) = color.GetColor();
}
void Image::Init(int width, int height,SDL_Renderer *renderer)
{
    this->width = width;
    this->height = height;
    pixels.resize(width*height);
    this->renderer = renderer;
    texture = NULL;
    InitTexture();
}
void Image::InitTexture()
{
                // IF ANY PREVOIUS TEXTURE IS LOADED, DESTROY IT
    if(texture != NULL)
        SDL_DestroyTexture(texture);

                // CREATE THE SURFACE
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height,32,0,0,0,255);
    if (!surface) {
        std::cerr << "SDL_CreateRGBSurface failed: " << SDL_GetError() << std::endl;
    }
    else {
        std::cout << "Surface pixel format: " << SDL_GetPixelFormatName(surface->format->format) << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
    }
    Uint32 format;
    int access, w, h;
    SDL_QueryTexture(texture, &format, &access, &w, &h);
    std::cout << "Texture format: " << SDL_GetPixelFormatName(format) << std::endl;

    SDL_FreeSurface(surface);
}
void Image::PrintPixels() {
    for(int i =0; i<pixels.size();i++)
        std::cout<<pixels[i]<<" ";
}
void Image::Display(){
    Color color = Color(255,255,0,0);

    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++)
        {

            SetPixel(x,y,color);
        }
    PrintPixels();
    std::cout<<"Finished setting pixel values"<<std::endl;
    if (SDL_UpdateTexture(texture, NULL, pixels.data(), width * sizeof(Uint32)) != 0) {
        std::cerr << "SDL_UpdateTexture failed: " << SDL_GetError() << std::endl;
    }

    //CREATE SOURCE AND DESTINATION RECTANGLES
    SDL_Rect source,dest;
    source.x = 0;
    source.y = 0;
    source.w = width;
    source.h = height;
    dest = source;
    SDL_RenderCopy(renderer,texture,&source,&dest);
}