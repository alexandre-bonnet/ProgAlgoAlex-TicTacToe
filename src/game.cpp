#include <iostream>
#include <array>
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"

void BattleDeuxJoueurs(Player premierJoueur, Player secondJoueur);
void gameModePlayersInit(gameBoard& board);
void activeGame(Player premierJoueur, Player secondJoueur, gameBoard& board);
void gameModeAiInit(gameBoard& board);
void playMove(Player joueur, gameBoard& board);
bool checkwin(gameBoard& board, Player Joueur);
void printEndMessage();

int gameInit(){
    gameBoard board;
    board.boardInit();
    std::cout<<"\n===========================\nBienvenue dans le TicTacToe d'Alex !\nVeuillez choisir un mode de jeu :\n";
    std::cout<<"1. Deux jouers.\n2. Un joueur contre l'IA\nEntrez 1 ou 2 : ";
    int a{0};
    std::cin >> a;
    while (a!=1 && a!=2){
        std::cout<<"ERROR : Entrez seulement 1 ou 2 : ";
        if(std::cin.fail()) {
            std::cin.clear(); // On remet std::cin dans un état fonctionnel.
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        }
        std::cin >> a;
    }
    if(a==1){
        gameModePlayersInit(board);
    } else {
        gameModeAiInit(board);
    }
    return a;
}

void gameModePlayersInit(gameBoard& board){
    std::cout<<"Mode Deux Joueurs actif\n";
    Player Joueur1;
    std::cout << "Joueur 1 ";
    Joueur1.playerInit();
    Player Joueur2;
    std::cout << "Joueur 2 ";
    Joueur2.playerInit();
    while (Joueur1.getName()==Joueur2.getName()||Joueur1.getSymbol()==Joueur2.getSymbol()){
        std::cout << "ERROR : Invalid entry. The name or symbol already in use" << std::endl << "Joueur 2 ";
        Joueur2.playerInit();
    }
    std::cout << "Joueur 1 : " << Joueur1.getName() << " -> " << Joueur1.getSymbol() << std::endl;
    std::cout << "Joueur 2 : " << Joueur2.getName() << " -> " << Joueur2.getSymbol() << std::endl;
    if (rand() % 2 == 0)
        activeGame(Joueur1, Joueur2, board);
    else
        activeGame(Joueur2, Joueur1, board);
}

void activeGame(Player premierJoueur, Player secondJoueur, gameBoard& board){
    board.drawGameBoard();
    for(int i = 0; i<4;i++){
        playMove(premierJoueur, board);
        if(checkwin(board,premierJoueur)){
            printEndMessage();
            break;
        }
        if(i>9){
            std::cout << "c'est une egalite";
            break;
        }
        playMove(secondJoueur, board);
        if(checkwin(board,premierJoueur)){
            printEndMessage();
            break;
        }
    } return;
}

void playMove(Player joueur, gameBoard& board){
    int a{};
    std::cout << joueur.getName() << " c'est votre tour : ";
    std::cin >> a;
    while(!board.isCellEmpty(a)||std::cin.fail()||(a>9||a<1)){
        if(std::cin.fail()){
            std::cin.clear(); // On remet std::cin dans un état fonctionnel.
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "ERROR : Entrez un numero de case valide. C'est votre tour : ";
        } else if(a>9||a<1){
            std::cout << "ERROR : Entrez un numero entre 1 et 9. C'est votre tour : ";
        } else if(!board.isCellEmpty(a)){
            std::cout << "ERROR : Entrez un numero de case vide. C'est votre tour : ";
        }
        std::cin >> a;
    }
    board.boardPlayMove(a,joueur);
    board.drawGameBoard();
}

void gameModeAiInit(gameBoard& board){
    std::cout<<"Mode IA actif\n";
    Player Joueur;
    Joueur.playerInit();
    if (Joueur.getSymbol()=='O')
        Player AI{"AI",'X'};
    else
        Player AI{"AI",'O'};
    board.boardPlayMove(1,Joueur);
}

bool checkwin(gameBoard& board, Player Joueur){
    for(int i{1};i<10;i+=3){
        if(board.getCellContent(i)==board.getCellContent(i+1)&&board.getCellContent(i)==board.getCellContent(i+2)&&!board.isCellEmpty(i)){
            std::cout << Joueur.getName() << " gagne ! "<<std::endl;
            return true;
        }
        if(board.getCellContent(i)==board.getCellContent(i+3)&&board.getCellContent(i)==board.getCellContent(i+6)&&!board.isCellEmpty(i)){
            std::cout << Joueur.getName() << " gagne ! "<<std::endl;
            return true;
        }
    } if(board.getCellContent(1)==board.getCellContent(5)&&board.getCellContent(1)==board.getCellContent(9)&&!board.isCellEmpty(5)){
        std::cout << Joueur.getName() << " gagne !"<<std::endl;
            return true;
    } if(board.getCellContent(3)==board.getCellContent(5)&&board.getCellContent(1)==board.getCellContent(7)&&!board.isCellEmpty(5)){
        std::cout << Joueur.getName() << " gagne !"<<std::endl;
            return true;
    }
    return false;
}

void printEndMessage(){
    std::cout<<" ____                         _ \n| __ ) _ __ __ ___   _____   | |\n|  _ \\| '__/ _` \\ \\ / / _ \\  | |\n| |_) | | | (_| |\\ V / (_) | |_|\n|____/|_|  \\__,_| \\_/ \\___/  (_)\n";
    return;
}