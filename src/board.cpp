#include <iostream>
#include <array>
#include "board.hpp"
#include "player.hpp"

void gameBoard::boardInit(){
    boardArray = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
}

void gameBoard::drawGameBoard(){
    std::cout<<"  ==========="<<std::endl;
    for(int j{0};j<3;j++){
        for(int i{0};i<3;i++){
            std::cout<<" | "<<boardArray[i+3*j];
        }
        std::cout<<" |"<<std::endl;
    }
    std::cout<<"  ==========="<<std::endl;
    return;
}

void gameBoard::boardPlayMove(int a,Player joueur){
    boardArray[a-1] = joueur.getSymbol();
    return;
}

bool gameBoard::isCellEmpty(int a){
    return boardArray[a-1]==char(32);
}

char gameBoard::getCellContent(int a){
    return boardArray[a-1];
}