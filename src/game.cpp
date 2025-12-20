#include <iostream>
#include <array>
#include <vector>
#include <time.h>
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"

void gameModeMultiplayerInit(gameBoard& board);
void gameModeSoloInit(gameBoard& board);
void activeMultiplayerGame(Player premierJoueur, Player secondJoueur, gameBoard& board);
void activeSoloGame(Player joueur, Player ai, gameBoard board);
void playMove(Player joueur, gameBoard& board);
void aiMove(Player ai, Player joueur, gameBoard& board);
void printGoodEndMessage();
void printBadEndMessage();

void gameInit(){
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
    (a==1) ? gameModeMultiplayerInit(board) : gameModeSoloInit(board);
    return;
}

void gameModeMultiplayerInit(gameBoard& board){
    std::cout<<"Mode Deux Joueurs actif\n";
    Player Joueur1;
    std::cout << "Joueur 1 ";
    Joueur1.playerInit();
    Player Joueur2;
    std::cout << "Joueur 2 ";
    Joueur2.playerInit();
    while (Joueur1.name==Joueur2.name||Joueur1.symbol==Joueur2.symbol){
        std::cout << "ERROR : Invalid entry. The name or symbol already in use" << std::endl << "Joueur 2 ";
        Joueur2.playerInit();
    }
    std::cout << "Joueur 1 : " << Joueur1.name << " -> " << Joueur1.symbol << std::endl;
    std::cout << "Joueur 2 : " << Joueur2.name << " -> " << Joueur2.symbol << std::endl;
    srand ( time(NULL) );
    (rand() % 2 == 0) ? activeMultiplayerGame(Joueur1, Joueur2, board) : activeMultiplayerGame(Joueur2, Joueur1, board);
}

void gameModeSoloInit(gameBoard& board){
    std::cout<<"Mode IA actif\n";
    Player joueur;
    joueur.playerInit();
    Player ai;
    (joueur.symbol=='O'||joueur.symbol=='o'||joueur.symbol=='0') ? ai.aiInit('X') : ai.aiInit('O') ;
    activeSoloGame(joueur, ai, board);
}

void activeMultiplayerGame(Player premierJoueur, Player secondJoueur, gameBoard& board){
    premierJoueur.setNumber(1);
    secondJoueur.setNumber(2);
    board.drawGameBoard(premierJoueur,secondJoueur);
    for(int i = 0; i<5;i++){
        playMove(premierJoueur, board);
        board.drawGameBoard(premierJoueur,secondJoueur);
        if(board.checkwin(premierJoueur)){
            printGoodEndMessage();
            return;
        }
        if((i)>3){
            std::cout << "c'est une egalite";
            return;
        }
        playMove(secondJoueur, board);
        board.drawGameBoard(premierJoueur,secondJoueur);
        if(board.checkwin(secondJoueur)){
            printGoodEndMessage();
            return;
        }
    }
    return;
}

void activeSoloGame(Player joueur, Player ai, gameBoard board){
    joueur.setNumber(1);
    for(int i = 0; i<5;i++){
        board.drawGameBoard(joueur,ai);
        playMove(joueur, board);
        if(board.checkwin(joueur)){
            printGoodEndMessage();
            return;
        }
        if((i)>3){
            std::cout << "C'est une egalite";
            return;
        }
        aiMove(ai, joueur ,board);
        if(board.checkwin(ai)){
            board.drawGameBoard(joueur,ai);
            printBadEndMessage();
            return;
        }
    }
    return;
}
void playMove(Player joueur, gameBoard& board){
    int a{};
    std::cout << joueur.name << " c'est votre tour : ";
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
    board.boardPlayMove(a,joueur.number);
}

void aiMove(Player ai, Player joueur, gameBoard& board){
    int lineSum{};
    int aiDoubleNum = 2*ai.number;
    int joueurDoubleNum = 2*joueur.number;
    bool winPriority = true;
    for(int j{0};j<2;j++){
        for(int i{1};i<10;i+=3){
            lineSum = board.getCellContent(i)+board.getCellContent(i+1)+board.getCellContent(i+2);
            if(lineSum==aiDoubleNum||(lineSum==joueurDoubleNum&&!winPriority)){
                board.boardPlayMove(board.getEmptyCell(i,i+1,i+2),ai.number);
                return;
            }
        } for(int i{1};i<4;i++){
            lineSum = board.getCellContent(i)+board.getCellContent(i+3)+board.getCellContent(i+6);
            if(lineSum==aiDoubleNum||(lineSum==joueurDoubleNum&&!winPriority)){
                board.boardPlayMove(board.getEmptyCell(i,i+3,i+6),ai.number);
                return;
            }
        } 
        lineSum = board.getCellContent(1)+board.getCellContent(5)+board.getCellContent(9);
        if(lineSum==aiDoubleNum||(lineSum==joueurDoubleNum&&!winPriority)){
            board.boardPlayMove(board.getEmptyCell(1,5,9),ai.number);
            return;
        } lineSum = board.getCellContent(3)*board.getCellContent(5)*board.getCellContent(7);
        if(lineSum==aiDoubleNum||(lineSum==joueurDoubleNum&&!winPriority)){
            board.boardPlayMove(board.getEmptyCell(3,5,7),ai.number);
            return;
        }
        winPriority=false;
    }
    std::vector<int> emptyCells;
    for(int i{1};i<10;i++){
        if(board.isCellEmpty(i)){
            emptyCells.push_back(i);
        }
    }
    srand ( time(NULL) );
    int a = rand()%(emptyCells.size());
    std::cout << "l'IA joue dans la case " << emptyCells[a]<<std::endl;
    board.boardPlayMove(emptyCells[a],ai.number);
    return;
}

void printGoodEndMessage(){
    std::cout<<" ____                         _ \n| __ ) _ __ __ ___   _____   | |\n|  _ \\| '__/ _` \\ \\ / / _ \\  | |\n| |_) | | | (_| |\\ V / (_) | |_|\n|____/|_|  \\__,_| \\_/ \\___/  (_)\n";
    return;
}

void printBadEndMessage(){
    std::cout<<"____              _             \n|  _ \\ ___ _ __ __| |_   _       \n| |_) / _ \\ '__/ _` | | | |      \n|  __/  __/ | | (_| | |_| |_ _ _ \n|_|   \\___|_|  \\__,_|\\__,_(_|_|_)\n";
}