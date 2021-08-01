#include "CApp.h"
#include "CAI.h"

#include <iostream>
#include <random>

CAI::CAI()
{
}

void CAI::NextMoveRand(int grid[9], int *player, int *turn)
{
    // AI is always the O player

    std::random_device rd;                         // obtain a random number from hardware
    std::mt19937 gen(rd());                        // seed the generator
    std::uniform_int_distribution<> distr(0, 8);   // define the range

    int cell;

    // find empty cell randomly and mark with O
    do
    {
        cell = distr(gen); 
    }
    while (grid[cell] != GRID_TYPE_NONE);
    // should call CApp::SetCell?
    grid[cell] = GRID_TYPE_O;

    // next player turn
    *player = 0;
    *turn = 0;

    return;
}
