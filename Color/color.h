#ifndef COLOR_H
#include <SDL.h>
#define COLOR_H
class Color{
    public:
    Color(float r, float g, float b, float a);
    Uint32 GetColor();

private:
    float red;
    float green;
    float blue;
    float alpha;
    Uint32 i_Color;
    Uint32 GetColorFromARGB(float r, float g, float b, float a);

};
#endif