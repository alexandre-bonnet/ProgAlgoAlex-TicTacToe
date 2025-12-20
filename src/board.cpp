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
            else if(boardArray[i+3*j]==joueur1.number)
            std::cout<<" | "<<joueur1.symbol;
            else if(boardArray[i+3*j]==joueur2.number)
            std::cout<<" | "<<joueur2.symbol;
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

int gameBoard::getEmptyCell(int a,int b,int c){
    if(isCellEmpty(a))
        return a;
    else if(isCellEmpty(b))
        return b;
    else if(isCellEmpty(c))
        return c;
    return -1;
}

bool gameBoard::checkwin(Player joueur){
    int joueurPow3 = joueur.number*joueur.number*joueur.number;
    for(int i{0}; i<3;i++){
        int row = 1+(3*i);
        if(getCellContent(row)*getCellContent(row+1)*getCellContent(row+2)==joueurPow3){
            std::cout << joueur.name << " gagne ! "<<std::endl;
            return true;
        }
        if(getCellContent(i+1)*getCellContent(i+4)*getCellContent(i+7)==joueurPow3){
            std::cout << joueur.name << " gagne ! "<<std::endl;
            return true;
        }
    } if(getCellContent(1)*getCellContent(5)*getCellContent(9)==joueurPow3 ||
     getCellContent(3)*getCellContent(5)*getCellContent(7)==joueurPow3){
        std::cout << joueur.name << " gagne !"<<std::endl;
            return true;
    }
    return false;
}