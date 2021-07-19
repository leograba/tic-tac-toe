#include "CApp.h"

void CApp::OnCleanup() {
    SDL_DestroyTexture(mytexture);

    if (renderer){
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window){
        SDL_DestroyWindow(window);
        window = NULL;
    }

    IMG_Quit();
    SDL_Quit();
}