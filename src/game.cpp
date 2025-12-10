#include <iostream>
#include <array>
#include <time.h>
#include <cmath>
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"

void battleMultiplayer(Player premierJoueur, Player secondJoueur);
void gameModeMultiplayerInit(gameBoard& board);
void activeMultiplayerGame(Player premierJoueur, Player secondJoueur, gameBoard& board);
void gameModeSoloInit(gameBoard& board);
void playMove(Player joueur, gameBoard& board, int number);
bool checkwin(gameBoard& board, Player Joueur);
void aiMove(Player ai, gameBoard& board);
void activeSoloGame(Player joueur, Player ai, gameBoard board);
void printEndGoodMessage();

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
        gameModeMultiplayerInit(board);
    } else {
        gameModeSoloInit(board);
    }
    return a;
}

void gameModeMultiplayerInit(gameBoard& board){
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
    srand ( time(NULL) );
    if (rand() % 2 == 0)
        activeMultiplayerGame(Joueur1, Joueur2, board);
    else
        activeMultiplayerGame(Joueur2, Joueur1, board);
}

void gameModeSoloInit(gameBoard& board){
    std::cout<<"Mode IA actif\n";
    Player joueur;
    joueur.playerInit();
    Player ai;
    if (joueur.getSymbol()=='O')
        ai.aiInit('X');
    else
        ai.aiInit('O');
    activeSoloGame(joueur, ai, board);
}

void activeMultiplayerGame(Player premierJoueur, Player secondJoueur, gameBoard& board){
    premierJoueur.setNumber(1);
    secondJoueur.setNumber(2);
    board.drawGameBoard(premierJoueur,secondJoueur);
    for(int i = 0; i<4;i++){
        playMove(premierJoueur, board,premierJoueur.getNumber());
        board.drawGameBoard(premierJoueur,secondJoueur);
        if(checkwin(board,premierJoueur)){
            printEndGoodMessage();
            break;
        }
        if(i>9){
            std::cout << "c'est une egalite";
            break;
        }
        playMove(secondJoueur, board,secondJoueur.getNumber());
        board.drawGameBoard(premierJoueur,secondJoueur);
        if(checkwin(board,secondJoueur)){
            printEndGoodMessage();
            break;
        }
    } return;
}

void activeSoloGame(Player joueur, Player ai, gameBoard board){
    joueur.setNumber(1);
    for(int i = 0; i<4;i++){
        playMove(joueur, board,joueur.getNumber());
        if(checkwin(board,joueur)){
            printEndGoodMessage();
            break;
        }
        if(i>9){
            std::cout << "c'est une egalite";
            break;
        }
        aiMove(ai, board);
        if(checkwin(board,ai)){
            std::cout << "AI gagne";
            break;
        } board.drawGameBoard(joueur,ai);
    } return;
}
void playMove(Player joueur, gameBoard& board, int number){
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
    board.boardPlayMove(a,number);
}

void aiMove(Player ai, gameBoard& board){
    int a = rand();
    while(!board.isCellEmpty(a%9+1)){
        srand ( time(NULL) );
        a = rand();
    }
    ai.getName();
    board.boardPlayMove(a,3);
    return;
}

bool checkwin(gameBoard& board, Player Joueur){
    int joueurPow3 = pow(Joueur.getNumber(),3);
    for(int i{1};i<10;i+=3){
        if(board.getCellContent(i)*board.getCellContent(i+1)*board.getCellContent(i+2)==joueurPow3){
            std::cout << Joueur.getName() << " gagne ! "<<std::endl;
            return true;
        }
        if(board.getCellContent(i)*board.getCellContent(i+3)*board.getCellContent(i+6)==joueurPow3){
            std::cout << Joueur.getName() << " gagne ! "<<std::endl;
            return true;
        }
    } if(board.getCellContent(1)*board.getCellContent(5)*board.getCellContent(9)==joueurPow3){
        std::cout << Joueur.getName() << " gagne !"<<std::endl;
            return true;
    } if(board.getCellContent(3)*board.getCellContent(5)*board.getCellContent(7)==joueurPow3){
        std::cout << Joueur.getName() << " gagne !"<<std::endl;
            return true;
    }
    return false;
}

void printEndGoodMessage(){
    std::cout<<" ____                         _ \n| __ ) _ __ __ ___   _____   | |\n|  _ \\| '__/ _` \\ \\ / / _ \\  | |\n| |_) | | | (_| |\\ V / (_) | |_|\n|____/|_|  \\__,_| \\_/ \\___/  (_)\n";
    return;
}