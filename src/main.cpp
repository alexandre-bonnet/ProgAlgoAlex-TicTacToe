#include <array>  
#include <iostream>
#include "Player.hpp"

struct Position {
    int x {0};
    int y {0};

    void display() {
        std::cout << x << " " << y << std::endl;
    }
};

enum class Direction {
    Up,
    Down,
    Forward,
    Backward
};

void drawGameBoard(std::array<char,9> board);
int gameMenu();

int main() {
    gameMenu();
    Player Joueur1;
    std::cout << "Joueur 1 ";
    //Joueur1.playerInit();
    Player Joueur2;
    std::cout << "Joueur 2 ";
    Joueur2.playerInit();
    while (Joueur1.getName()==Joueur2.getName()||Joueur1.getSymbol()==Joueur2.getSymbol()){
        std::cout << "ERROR : Invalid entry. The name or symbol already in use" << std::endl << "Joueur 2 ";
        Joueur2.playerInit();
    }
    std::cout << "Joueur 1 : " << Joueur1.getName() << " -> " << Joueur1.getSymbol() << std::endl;
    std::cout << "Joueur 2 : " << Joueur2.getName() << " -> " << Joueur2.getSymbol() << std::endl;
    std::array<char,9>board = {'1','2','3','4','5','6','7','8','9'};
    drawGameBoard(board);
    return 0;
}

void drawGameBoard(std::array<char,9> board){
    std::cout<<"  ==========="<<std::endl;
    for(int j{0};j<3;j++){
        for(int i{0};i<3;i++){
            std::cout<<" | "<<board[i+3*j];
        }
        std::cout<<" |"<<std::endl;
    }
    std::cout<<"  ==========="<<std::endl;
    return;
}

int gameMenu(){
    std::cout<<"\n===========================\nBienvenue dans le TicTacToe d'Alex !\nVeuillez choisir un mode de jeu :\n";
    std::cout<<"1. Deux jouers.\n2. Un joueur contre l'IA\nEntrez 1 ou 2 :";
    int a{0};
    std::cin >> a;
    while (a!=1 && a!=2){
        std::cout<<"ERROR : Entrez seulement 1 ou 2 :";
        std::cin >> a;
    }
    return a;
}