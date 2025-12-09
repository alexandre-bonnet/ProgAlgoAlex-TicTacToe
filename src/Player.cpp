#include <iostream>
#include "Player.hpp"

void Player::playerInit(){
    std::cout << "entrez votre nom : ";
    std::cin >> name;
    std::cout << std::endl <<  "Choissisez un symbole : ";
    std::cin >> symbol;
}
std::string Player::getName(){
    return name;
}
char Player::getSymbol(){
    return symbol;
}