#pragma once
#include "player.hpp"
#include "board.hpp"

int gameInit();
void BattleDeuxJoueurs(Player premierJoueur, Player secondJoueur);
void gameModePlayersInit(gameBoard& board);
void gameModeAiInit(gameBoard& board);
void activeGame(Player premierJoueur, Player secondJoueur, gameBoard& board);
void playMove(Player joueur, gameBoard& board);
bool checkwin(gameBoard& board, Player Joueur);