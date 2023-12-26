#include "color.h"
#include <iostream>
Uint32 Color::GetColorFromARGB(double r, double g, double b,double a) {
    Uint32 color = (static_cast<Uint32>(a * 255.0) << 24
                    | static_cast<Uint32>(b * 255.0) << 16
                    | static_cast<Uint32>(g * 255.0) << 8
                    | static_cast<Uint32>(r * 255.0));

    return color;
}
Uint32 Color::GetColor() { return this->i_Color;}
Color::Color(double r, double g, double b, double a)
{
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
    this->i_Color = GetColorFromARGB(r, g, b, a);
}