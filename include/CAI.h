#ifndef _CAI_H_
#define _CAI_H_

class CAI
{
private:
    enum
    {
        GRID_TYPE_NONE = 0,
        GRID_TYPE_X,
        GRID_TYPE_O
    };

public:
    CAI();

public:
    static void NextMoveRand(int grid[9], int *player, int *turn);
};

#endif
