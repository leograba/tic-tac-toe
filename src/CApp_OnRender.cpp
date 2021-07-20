#include "CApp.h"

void CApp::OnRender()
{
    SDL_RenderClear(renderer);
    CTexture::OnDraw(renderer, mytexture, 0, 0);
    CTexture::OnDraw(renderer, mytexture, 100, 100, 0, 0, 50, 35);
    SDL_RenderPresent(renderer);
}