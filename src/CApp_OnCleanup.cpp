#include "CApp.h"

void CApp::OnCleanup() {
    SDL_DestroyTexture(grid);
    SDL_DestroyTexture(mark_x);
    SDL_DestroyTexture(mark_o);

    if (app.renderer){
        SDL_DestroyRenderer(app.renderer);
        app.renderer = NULL;
    }

    if (app.window)
    {
        SDL_DestroyWindow(app.window);
        app.window = NULL;
    }

    IMG_Quit();
    SDL_Quit();
}