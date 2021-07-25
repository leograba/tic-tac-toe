#include "CApp.h"
#include <iostream>
#include <algorithm>

void CApp::OnEvent(SDL_Event *Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnLButtonDown(int mX, int mY)
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

    CheckWinner();
}

void CApp::OnResize(int width, int height)
{
    app.width = width;
    app.height = height;
    app.grid_size = std::min(width, height);
    app.mark_size = app.grid_size / 3;
    SDL_RenderSetLogicalSize(app.renderer, app.width, app.height);
}

void CApp::OnExit()
{
    app.Running = false;
}