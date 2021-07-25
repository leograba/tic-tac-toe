#include "CApp.h"
#include <iostream>

void CApp::OnRender()
{
    int *win_w = NULL;
    int *win_h = NULL;
    SDL_GetWindowSize(window, win_w, win_h);

    SDL_RenderClear(renderer);

    //some tests to understand position
    //CTexture::OnDraw(renderer, grid);
    //CTexture::OnDraw(renderer, grid, 0, 0);
    //CTexture::OnDraw(renderer, mark_x, 160, 0, 160, 160);
    //CTexture::OnDraw(renderer, mark_o, 320, 0, 160, 160);

    //draw the grid
    CTexture::OnDraw(renderer, grid, 160, 0, 480, 480);

    //draw the X's and O's
    for (int i = 0; i < 9; i++)
    {
        int x = (i % 3) * 160 + 160;
        int y = (i / 3) * 160;

        if (GridStatus[i] == GRID_TYPE_X)
        {
            CTexture::OnDraw(renderer, mark_x, x, y, 160, 160);
        }
        else if (GridStatus[i] == GRID_TYPE_O)
        {
            CTexture::OnDraw(renderer, mark_o, x, y, 160, 160);
        }
    }
    SDL_RenderPresent(renderer);

    //tell who is the winner

    if (Winner != -1)
    {
        SDL_RenderClear(renderer);
        switch (Winner)
        {
        case GRID_TYPE_NONE: // draw
            CTexture::OnDraw(renderer, grid, 160, 0, 480, 480);
            CTexture::OnDraw(renderer, mark_x, 0, 0, 480, 480);
            CTexture::OnDraw(renderer, mark_o, 320, 0, 480, 480);
            break;
        case GRID_TYPE_X: // X win
            CTexture::OnDraw(renderer, grid, 160, 0, 480, 480);
            CTexture::OnDraw(renderer, mark_x);
            break;
        case GRID_TYPE_O: // O win
            CTexture::OnDraw(renderer, grid, 160, 0, 480, 480);
            CTexture::OnDraw(renderer, mark_o);
            break;
        default:
            std::cerr << "Unknown winner value, exiting: " << Winner << "\n";
            exit(1);
        }
        SDL_RenderPresent(renderer);
        Reset(GAME_RESTART);
    }

}