#include "CApp.h"
#include "CAI.h"

void CApp::OnLoop()
{

    if (app.State == STATE_DEFAULT)
    {
        // play against AI, if configured
        if (VersusAI != 0 && AITurn == 1 && CurrentPlayer == 1)
        {
            CAI::NextMoveRand(GridStatus, &CurrentPlayer, &AITurn);
            SDL_Delay(1000);
            CheckWinner();
        }
    }
    else if (app.State == STATE_WIN)
    {
        // Do nothing
    }
    else if (app.State == STATE_MENU)
    {
        // Do nothing
    }
}