#include <iostream>
#include "image.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
const uint32_t R_MASK = 0xff000000;
const uint32_t G_MASK = 0x00ff0000;
const uint32_t B_MASK = 0x0000ff00;
const uint32_t A_MASK = 0x000000ff;
#else
const uint32_t R_MASK = 0x000000ff;
    const uint32_t G_MASK = 0x0000ff00;
    const uint32_t B_MASK = 0x00ff0000;
    const uint32_t A_MASK = 0xff000000;
#endif

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
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height,32,R_MASK,G_MASK,B_MASK,A_MASK);
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

                        //r a b g
    Color color = Color(1.0f, 1.0f, 0.0f, 1.0f); // Opaque Red


    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++)
        {

            SetPixel(x,y,color);
        }


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