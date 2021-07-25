#include "CApp.h"

void CApp::OnRender()
{
    int *win_w = NULL;
    int *win_h = NULL;
    SDL_GetWindowSize(window, win_w, win_h);

    SDL_RenderClear(renderer);
    //CTexture::OnDraw(renderer, grid);
    //CTexture::OnDraw(renderer, grid, 0, 0);
    CTexture::OnDraw(renderer, grid, 160, 0, 480, 480);
    SDL_RenderPresent(renderer);
}