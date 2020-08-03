#pragma once
class NaughtsCrosses { 

    int board[9] = {0,0,0,0,0,0,0,0,0};

    const int NAUGHT = 1;
    const int CROSS = 2;

    void PrintBoard();
    bool CheckMoveAvailability(int player, int position);
    int GetPosition(int player);
    int CheckWinConditions();
public:
    void Start();
};