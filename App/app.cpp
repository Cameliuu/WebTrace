#include "app.h"
#include "../Image/image.h"
#include <iostream>
App::App()
{
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}
bool App::onInit(){
            // Initialize SDL Library with all it s subsystems
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;
    //CREATE A WINDOW In the center of the screen of size 1280/720 called WebTraces
    pWindow = SDL_CreateWindow("WebTrace",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
    if(pWindow != NULL)
    {
        //Create a sdl renderer
        pRenderer = SDL_CreateRenderer(pWindow,-1,0);
        if(pRenderer == NULL)
            return false;

        //  Create the image
        image.Init(1280,720,pRenderer);
    }
    else
    {
        return false;
    }

    return true;
}
void App::OnExit(){
            //FREE RESOURCES WHEN EXITING
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}
void App::OnEvent(SDL_Event *pEvent) {
    //CHECK IF THE EVENT IS OF TYPE QUIT
    //IF SO, SET IS RUNNING TO FALSE, WHILE LOOP WILL EXIT
    if(pEvent->type == SDL_QUIT)
    {
        isRunning = false;
    }
}
void App::OnLoop() {}
void App::OnRender(){

    // Set the background colour to white.
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    //Rende the scene
    scene.Render(image);


    // Display the image.

        image.Display();

    // Show the result.
    SDL_RenderPresent(pRenderer);
}
//entry point of the app
int App::Start(){
    SDL_Event event;
    //Check if the initialization was successful
    if(onInit() == false)
        return -1;
    while(isRunning)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
    OnExit();
}