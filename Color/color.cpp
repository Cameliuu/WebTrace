#include "color.h"

Uint32 Color::GetColorFromARGB(float r, float g, float b,float a) {
    Uint32 color = (static_cast<Uint32>(r) << 24
                    | static_cast<Uint32>(g) << 16
                    | static_cast<Uint32>(b) << 8
                    | static_cast<Uint32>(a));

    return color;
}
Uint32 Color::GetColor() { return this->i_Color;}
Color::Color(float r, float g, float b, float a)
{
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
    this->i_Color = GetColorFromARGB(r, g, b, a);
}