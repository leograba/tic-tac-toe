#include "CApp.h"

void CApp::OnCleanup() {
    SDL_DestroyTexture(grid);
    SDL_DestroyTexture(mark_x);
    SDL_DestroyTexture(mark_o);

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