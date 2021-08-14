#include "CApp.h"

void CApp::OnCleanup() {
    SDL_DestroyTexture(menu_button);
    SDL_DestroyTexture(grid);
    SDL_DestroyTexture(mark_x);
    SDL_DestroyTexture(mark_o);
    SDL_DestroyTexture(text_header);
    SDL_DestroyTexture(text_player_x);
    SDL_DestroyTexture(text_player_o);
    TTF_CloseFont(font);

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
    TTF_Quit();
    SDL_Quit();
}