#ifndef COLOR_H
#include <SDL.h>
#define COLOR_H
class Color{
    public:
    Color(double r, double g, double b, double a);
    Uint32 GetColor();

private:
    float red;
    float green;
    float blue;
    float alpha;
    Uint32 i_Color;
    Uint32 GetColorFromARGB(double r, double g, double b, double a);

};
#endif