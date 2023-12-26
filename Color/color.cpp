#include "color.h"
#include <iostream>

//r a b g
Uint32 Color::GetColorFromABGR(float a, float r, float g, float b) {

    Uint32 color = (static_cast<Uint8>(a * 255.0f) << 24)
                   | (static_cast<Uint8>(b * 255.0f) << 16)
                   | (static_cast<Uint8>(g * 255.0f) << 8)
                   | static_cast<Uint8>(r * 255.0f);

    return color;
}

Uint32 Color::GetColor() { return this->i_Color;}
Color::Color(float a, float r, float g, float b)
{
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
    this->i_Color = GetColorFromABGR(a, r, g, b);
}