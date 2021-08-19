#include "CApp.h"
#include <iostream>

void CApp::OnRender()
{

    if (app.State == STATE_DEFAULT)
    {
        //clear the screen
        SDL_RenderClear(app.renderer);

        //draw the grid
        CTexture::OnDraw(app.renderer, grid, 0, 0, app.grid_size, app.grid_size);

        //draw the X's and O's
        for (int i = 0; i < 9; i++)
        {
            int x = (i % 3) * app.mark_size;
            int y = (i / 3) * app.mark_size;

            if (GridStatus[i] == GRID_TYPE_X)
            {
                CTexture::OnDraw(app.renderer, mark_x, x, y, app.mark_size, app.mark_size);
            }
            else if (GridStatus[i] == GRID_TYPE_O)
            {
                CTexture::OnDraw(app.renderer, mark_o, x, y, app.mark_size, app.mark_size);
            }
        }

        //draw the scoreboard
        CText::OnDraw(app.renderer, text_header, font, "Placar", app.width,
                    app.grid_size, app.height / 5);
        CText::OnDraw(app.renderer, text_header, font, "Jogador X", app.width,
                    app.grid_size, app.height / 5 + 2 * TTF_FontLineSkip(font));
        CText::OnDraw(app.renderer, text_header, font, std::to_string(score.score_x),
                    app.width, app.grid_size, app.height / 5 + 3 * TTF_FontLineSkip(font));
        CText::OnDraw(app.renderer, text_header, font, "Jogador O", app.width,
                    app.grid_size, app.height / 5 + 5 * TTF_FontLineSkip(font));
        CText::OnDraw(app.renderer, text_header, font, std::to_string(score.score_o),
                    app.width, app.grid_size, app.height / 5 + 6 * TTF_FontLineSkip(font));
        CText::OnDraw(app.renderer, text_header, font, "Empate", app.width,
                    app.grid_size, app.height / 5 + 8 * TTF_FontLineSkip(font));
        CText::OnDraw(app.renderer, text_header, font, std::to_string(score.score_tie),
                    app.width, app.grid_size, app.height / 5 + 9 * TTF_FontLineSkip(font));

        //draw the sign to go back to the menu
        CTexture::OnDraw(app.renderer, back_button, app.menubtn_back);

        SDL_RenderPresent(app.renderer);
    }
    else if (app.State == STATE_WIN)
    {
        //tell who is the winner
        SDL_RenderClear(app.renderer);
        CTexture::OnDraw(app.renderer, grid, 0, 0, app.grid_size, app.grid_size);
        switch (Winner)
        {
        case GRID_TYPE_NONE: // draw
            CTexture::OnDraw(app.renderer, mark_x,
                            0, app.grid_size / 4,
                            app.grid_size / 2 , app.grid_size / 2);
            CTexture::OnDraw(app.renderer, mark_o,
                            app.grid_size / 2, app.grid_size / 4,
                            app.grid_size / 2, app.grid_size / 2);
            break;
        case GRID_TYPE_X: // X win
            CTexture::OnDraw(app.renderer, mark_x, 0, 0, app.grid_size, app.grid_size);
            break;
        case GRID_TYPE_O: // O win
            CTexture::OnDraw(app.renderer, mark_o, 0, 0, app.grid_size, app.grid_size);
            break;
        default:
            std::cerr << "Unknown winner value, exiting: " << Winner << "\n";
            exit(1);
        }
        SDL_RenderPresent(app.renderer);
    }
    else if (app.State == STATE_MENU)
    {
        //clear the screen
        SDL_RenderClear(app.renderer);

        //draw the buttons
        CTexture::OnDraw(app.renderer, menu_button, app.menubtn_vsplayer);
        CTexture::OnDraw(app.renderer, menu_button, app.menubtn_vscomputer);

        //draw the text
        CText::OnDraw(app.renderer, text_header, font, "Escolha seu oponente",
                      app.width, 0, app.height / 5);
        CText::OnDraw(app.renderer, text_header, font, "Outro Jogador",
                      app.menubtn_vsplayer);
        CText::OnDraw(app.renderer, text_header, font, "Computador",
                      app.menubtn_vscomputer);

        SDL_RenderPresent(app.renderer);
    }

}