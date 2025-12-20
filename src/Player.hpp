#pragma once
struct Player{
    std::string name;
    char symbol;
    int number;
    void playerInit();
    void aiInit(char pSymbol);
    void setNumber(int a);
};