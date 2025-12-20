#pragma once
#include<array>
#include "player.hpp"
struct gameBoard{
    std::array<int,9>boardArray;
    void boardInit();
    void drawGameBoard(Player joueur1,Player Joueur2);
    void boardPlayMove(int a,int b);
    bool isCellEmpty(int a);
    int getCellContent(int a);
    int getEmptyCell(int a,int b,int c);
    bool checkwin(Player Joueur);
};