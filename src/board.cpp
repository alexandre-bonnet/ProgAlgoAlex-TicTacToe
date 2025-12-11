#include <iostream>
#include <array>
#include "board.hpp"
#include "player.hpp"

void gameBoard::boardInit(){
    boardArray = {0,0,0,0,0,0,0,0,0};
}

void gameBoard::drawGameBoard(Player joueur1,Player joueur2){
    std::cout<<"  ==========="<<std::endl;
    for(int j{0};j<3;j++){
        for(int i{0};i<3;i++){
            if(boardArray[i+3*j]==0)
            std::cout<<" |  ";
            else if(boardArray[i+3*j]==joueur1.getNumber())
            std::cout<<" | "<<joueur1.getSymbol();
            else if(boardArray[i+3*j]==joueur2.getNumber())
            std::cout<<" | "<<joueur2.getSymbol();
            else 
            std::cout<<" | -";
        }
        std::cout<<" |"<<std::endl;
    }
    std::cout<<"  ==========="<<std::endl;
    return;
}

void gameBoard::boardPlayMove(int a,int b){
    boardArray[a-1] = b;
    return;
}

bool gameBoard::isCellEmpty(int a){
    return boardArray[a-1]==0;
}

int gameBoard::getCellContent(int a){
    return boardArray[a-1];
}