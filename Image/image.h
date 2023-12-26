#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <SDL.h>
#include "../Color/color.h"

class Image
{
    public:

    Image();
    ~Image();
    Uint32 GetLinearPosition(int x, int y);
    void Init(int width,int height, SDL_Renderer *renderer);
    void SetPixel(int x, int y, Color color);
    void InitTexture();
    void Display();
    void PrintPixels();
    int GetWidth();
    int GetHeight();
    private:
    int width;
    int height;
    std::vector<Uint32> pixels;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
};
#endif