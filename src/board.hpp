#pragma once
#include<array>
#include "player.hpp"
struct gameBoard{
    std::array<char,9>boardArray;
    void boardInit();
    void drawGameBoard();
    void boardPlayMove(int move, Player joueur);
    bool isCellEmpty(int a);
    char getCellContent(int a);
};