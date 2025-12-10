#pragma once
struct Player{
    std::string name;
    char symbol;
    int number{};
    void playerInit();
    std::string getName();
    char getSymbol();
    void aiInit(char pSymbol);
    void setNumber(int a);
    int getNumber();
};