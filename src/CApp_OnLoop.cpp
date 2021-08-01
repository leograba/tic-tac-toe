#include "CApp.h"
#include "CAI.h"

void CApp::OnLoop() {

    // play against AI, if configured
    if (VersusAI != 0 && AITurn == 1 && CurrentPlayer == 1)
    {
        CAI::NextMoveRand(GridStatus, &CurrentPlayer, &AITurn);
        SDL_Delay(1000);
        CheckWinner();
    }
}