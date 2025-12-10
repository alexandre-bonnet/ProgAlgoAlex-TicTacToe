#pragma once
#include "player.hpp"
#include "board.hpp"

int gameInit();
void battleMultiplayer(Player premierJoueur, Player secondJoueur);
void gameModeMultiplayerInit(gameBoard& board);
void gameModeSoloInit(gameBoard& board);
void activeGame(Player premierJoueur, Player secondJoueur, gameBoard& board);
void playMove(Player joueur, gameBoard& board);
bool checkwin(gameBoard& board, Player Joueur);