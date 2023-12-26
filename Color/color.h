#ifndef COLOR_H
#include <SDL.h>
#define COLOR_H
class Color{
    public:
    Color(float a, float r, float g, float b);
    Uint32 GetColor();

private:
    float red;
    float green;
    float blue;
    float alpha;
    Uint32 i_Color;
    Uint32 GetColorFromAGBR(float a, float r, float g, float b);

};
#endif