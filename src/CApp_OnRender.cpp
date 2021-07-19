#include "CApp.h"

void CApp::OnRender()
{
    SDL_RenderClear(renderer);
    CTexture::OnDraw(renderer, mytexture, 0, 0);
    SDL_RenderPresent(renderer);
}