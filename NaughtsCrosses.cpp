#include "NaughtsCrosses.h"
#include <iostream>

void NaughtsCrosses::PrintBoard()
{
    system("cls");
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0) std::cout << '\n';
        if (board[i] == NAUGHT)
        {
            std::cout << 'O';
        }
        else if (board[i] == CROSS)
        {
            std::cout << 'X';
        }
        else
        {
            std::cout << '-';
        }
    }

    std::cout << '\n';
}

bool NaughtsCrosses::CheckMoveAvailability(int player, int position)
{
    if (board[position] == 0)
        return true;

    else if (board[position] == NAUGHT)
    {
        std::cout << "Position taken by Naught" << std::endl;
        return false;
    }
    else if (board[position] == CROSS)
    {
        std::cout << "Position taken by Cross" << std::endl;
        return false;
    }
    else if (position < 0 || position > 8)
    {
        std::cout << "Position out of range" << std::endl;
        return false;
    }

    else return false;
}

int NaughtsCrosses::GetPosition(int player)
{
    int position = 0;
    std::cout << "Make your move: ";
    std::cin >> position;

    if (std::cin.fail()) // If the user didn't input a number
    {
        std::cin.clear(); // Reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip bad input

        GetPosition(player);
    }

    position -= 1;

    if (CheckMoveAvailability(player, position))
        return position;

    else
        GetPosition(player);
}

int NaughtsCrosses::CheckWinConditions()
{
    // Check horizontal line win condition
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == NAUGHT && board[i + 1] == NAUGHT && board[i + 2] == NAUGHT) return NAUGHT;
        else if (board[i] == CROSS && board[i + 1] == CROSS && board[i + 2] == CROSS) return CROSS;
    }

    // Check vertical line win condition
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == NAUGHT && board[i + 3] == NAUGHT && board[i + 6] == NAUGHT) return NAUGHT;
        else if (board[i] == CROSS && board[i + 3] == CROSS && board[i + 6] == CROSS) return CROSS;
    }

    // Check for diagonal win conditional left
    if (board[0] == NAUGHT && board[4] == NAUGHT && board[8] == NAUGHT) return NAUGHT;
    else if (board[0] == CROSS && board[4] == CROSS && board[8] == CROSS) return CROSS;

    // Check for diagonal win conditional right
    if (board[2] == NAUGHT && board[4] == NAUGHT && board[6] == NAUGHT) return NAUGHT;
    else if (board[2] == CROSS && board[4] == CROSS && board[6] == CROSS) return CROSS;

    // Check for draw
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0) return -1;
    }

    return 0;
}

void NaughtsCrosses::Start()
{
    int CurrentPlayer = CROSS;
    int turn = 0;
    while (true)
    {
        if (CurrentPlayer == NAUGHT)
            CurrentPlayer = CROSS;
        else
            CurrentPlayer = NAUGHT;

        PrintBoard();
        board[GetPosition(CurrentPlayer)] = CurrentPlayer;

        if (turn > 2)
        {
            if (CheckWinConditions() == NAUGHT)
            {
                PrintBoard();
                std::cout << "Naughts wins!" << std::endl;
                break;
            }
            else if (CheckWinConditions() == CROSS)
            {
                PrintBoard();
                std::cout << "Crosses wins!" << std::endl;
                break;
            }
            else if (CheckWinConditions() == 0)
            {
                PrintBoard();
                std::cout << "It's a draw!" << std::endl;
                break;
            }
        }

        turn++;
    }
}