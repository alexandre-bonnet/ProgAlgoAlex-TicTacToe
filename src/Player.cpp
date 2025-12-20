#include <iostream>
#include "player.hpp"

void Player::playerInit(){
    std::cout << "entrez votre nom : ";
    std::cin >> name;
    std::cout <<  "Choissisez un symbole : ";
    std::cin >> symbol;
}

void Player::aiInit(char pSymbol){
    name = "AI";
    symbol = pSymbol;
    number = 3;
}

void Player::setNumber(int a){
    number = a;
}