#include "CApp.h"
#include "CAI.h"

using namespace std::literals;

void CApp::OnLoop()
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (now - last_action);
    const auto wait_time = std::chrono::milliseconds(1000);

    if (app.State == STATE_DEFAULT)
    {
        // play against AI, if configured
        if (VersusAI !=0)
        {
            if (AITurn == 1 && CurrentPlayer == 1) // AI turn
            {
                // delay AI action to emulate a user
                if (elapsed.count() > wait_time.count())
                {
                    CAI::NextMoveRand(GridStatus, &CurrentPlayer, &AITurn);
                    last_action = std::chrono::steady_clock::now();
                    AITurn = 0;
                }
            }
            else // player turn
            {
                last_action = std::chrono::steady_clock::now();
            }
        }
        // two players
        else
        {
            last_action = std::chrono::steady_clock::now();
        }

        CheckWinner();
    }
    else if (app.State == STATE_WIN)
    {
        // Do nothing until after 5 seconds
        if (elapsed.count() > 5 * wait_time.count())
            Reset();
    }
    else if (app.State == STATE_MENU)
    {
        // Do nothing
    }
}