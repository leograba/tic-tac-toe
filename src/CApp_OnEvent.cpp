#include "CApp.h"
#include <iostream>
#include <algorithm>

void CApp::OnEvent(SDL_Event *Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnLButtonDown(int mX, int mY)
{
    if (app.State == STATE_DEFAULT)
    {
        // The grid is a square, don't accept clicks outside it
        if (mX > app.grid_size || mY > app.grid_size)
        {
            return;
        }

        int ID = (mX) / 160;
        ID = ID + ((mY / 160) * 3);

        if (GridStatus[ID] != GRID_TYPE_NONE)
        {
            return;
        }

        if (AITurn == 1) // AI turn
        {
            // just ignore user clicks
        }
        else{ // User turn
            if (CurrentPlayer == 0)
            {
                SetCell(ID, GRID_TYPE_X);
                CurrentPlayer = 1;
            }
            else
            {
                SetCell(ID, GRID_TYPE_O);
                CurrentPlayer = 0;
            }
        }
    }
    else if (app.State == STATE_WIN)
    {
        // Do nothing
    }
    else if (app.State == STATE_MENU)
    {
        // Capture user choice and start the game
        bool start = false;

        // Check vs player
        if ((mX > app.menubtn_vsplayer.x)
            && (mX < (app.menubtn_vsplayer.x + app.menubtn_vsplayer.w))
            && (mY > app.menubtn_vsplayer.y)
            && (mY < (app.menubtn_vsplayer.y + app.menubtn_vsplayer.h)))
        {
            VersusAI = 0;
            start = true;
        }

        // Check vs computer
        if ((mX > app.menubtn_vscomputer.x)
            && (mX < (app.menubtn_vscomputer.x + app.menubtn_vscomputer.w))
            && (mY > app.menubtn_vscomputer.y)
            && (mY < (app.menubtn_vscomputer.y + app.menubtn_vscomputer.h)))
        {
            VersusAI = 1;
            start = true;
        }

        if (start == true)
        {
            app.State = STATE_DEFAULT;
            Reset();
        }
    }
}

void CApp::OnResize(int width, int height)
{
    app.width = width;
    app.height = height;
    app.grid_size = std::min(width, height);
    app.mark_size = app.grid_size / 3;

    if (app.State == STATE_DEFAULT)
    {
        // No special calculation
    }

    else if (app.State == STATE_WIN)
    {
        // Do nothing
    }
    else if (app.State == STATE_MENU)
    {
        // Resize menu buttons
        app.menubtn_vsplayer.w = 0.35 * app.width;
        app.menubtn_vsplayer.h = app.menubtn_vsplayer.w / app.MENUBTN_RATIO;
        app.menubtn_vsplayer.x = 0.1 * app.width;
        app.menubtn_vsplayer.y = (app.height - app.menubtn_vsplayer.h) / 2;

        app.menubtn_vscomputer.w = app.menubtn_vsplayer.w;
        app.menubtn_vscomputer.h = app.menubtn_vsplayer.h;
        app.menubtn_vscomputer.x = 0.55 * app.width;
        app.menubtn_vscomputer.y = app.menubtn_vsplayer.y;
    }

    SDL_RenderSetLogicalSize(app.renderer, app.width, app.height);
}

void CApp::OnExit()
{
    app.Running = false;
}