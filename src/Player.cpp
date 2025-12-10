#include <iostream>
#include "player.hpp"

void Player::playerInit(){
    std::cout << "entrez votre nom : ";
    std::cin >> name;
    std::cout <<  "Choissisez un symbole : ";
    std::cin >> symbol;
}
std::string Player::getName(){
    return name;
}
char Player::getSymbol(){
    return symbol;
}

void Player::aiInit(char pSymbol){
    name = "AI";
    symbol = pSymbol;
}

void Player::setNumber(int a){
    number = a;
}

int Player::getNumber(){
    return number;
}