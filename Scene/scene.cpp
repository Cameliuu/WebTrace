#include "scene.h"

Scene::Scene(){}

void Scene::Render(Image& image){
        int witdth = image.GetWidth();
        int height = image.GetHeight();
        for(int x=0; x<witdth; x++){
            for(int y=0; y<height; y++){
                double red = static_cast<double>(x)/static_cast<double>(witdth);
                double green = static_cast<double>(y)/static_cast<double>(height);
                Color color = Color(red,green,0.0,1.0);
                image.SetPixel(x,y,color);
            }
        }
}