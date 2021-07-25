#include "CApp.h"
#include <iostream>
#include <algorithm>

void CApp::OnEvent(SDL_Event *Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnLButtonDown(int mX, int mY)
{
    std::cout << "x / y are: " << mX << " / " << mY << std::endl;
    // The grid is a square, don't accept clicks outside it
    if (mX > std::min(app.width, app.height))
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

void CApp::OnExit()
{
    app.Running = false;
}