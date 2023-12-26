
#ifndef APP_H
#define APP_H
#include <SDL.h>
#include "../Image/image.h"
#include "../Scene/scene.h"
class App {
public:
    App();
    bool onInit();
    int Start();
    void OnEvent(SDL_Event* pEvent);
    void OnLoop();
    void OnRender();
    void OnExit();
private:
    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Image image;
    Scene scene;
};
#endif