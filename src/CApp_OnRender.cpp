#include "CApp.h"
#include <iostream>
#include <algorithm>

void CApp::OnRender()
{

    SDL_GetWindowSize(app.window, &app.width, &app.height);
    int min_dim = std::min(app.width, app.height);
    int third = min_dim / 3;
    SDL_RenderClear(app.renderer);

    //some tests to understand position
    //CTexture::OnDraw(renderer, grid);
    //CTexture::OnDraw(renderer, grid, 0, 0);
    //CTexture::OnDraw(renderer, mark_x, 160, 0, 160, 160);
    //CTexture::OnDraw(renderer, mark_o, 320, 0, 160, 160);

    //draw the grid
    CTexture::OnDraw(app.renderer, grid, 0, 0, min_dim, min_dim);

    //draw the X's and O's
    for (int i = 0; i < 9; i++)
    {
        int x = (i % 3) * third;
        int y = (i / 3) * third;

        if (GridStatus[i] == GRID_TYPE_X)
        {
            CTexture::OnDraw(app.renderer, mark_x, x, y, third, third);
        }
        else if (GridStatus[i] == GRID_TYPE_O)
        {
            CTexture::OnDraw(app.renderer, mark_o, x, y, third, third);
        }
    }
    SDL_RenderPresent(app.renderer);

    //tell who is the winner

    if (Winner != -1)
    {
        SDL_RenderClear(app.renderer);
        switch (Winner)
        {
        case GRID_TYPE_NONE: // draw
            CTexture::OnDraw(app.renderer, grid, 0, 0, min_dim, min_dim);
            CTexture::OnDraw(app.renderer, mark_x, 0, 0, min_dim, min_dim);
            CTexture::OnDraw(app.renderer, mark_o, app.width - min_dim, 0, min_dim, min_dim);
            break;
        case GRID_TYPE_X: // X win
            CTexture::OnDraw(app.renderer, grid, 0, 0, min_dim, min_dim);
            CTexture::OnDraw(app.renderer, mark_x);
            break;
        case GRID_TYPE_O: // O win
            CTexture::OnDraw(app.renderer, grid, 0, 0, min_dim, min_dim);
            CTexture::OnDraw(app.renderer, mark_o);
            break;
        default:
            std::cerr << "Unknown winner value, exiting: " << Winner << "\n";
            exit(1);
        }
        SDL_RenderPresent(app.renderer);
        Reset(GAME_RESTART);
    }

}