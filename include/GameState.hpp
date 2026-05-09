#pragma once 
#include <string>
#include "GameHUD.hpp"
#include "Cmd.hpp"

class GameState { 
private:
    int state;
    std::string passInput;
public:
    GameState();
    ~GameState() = default;
    void process(std::map<std::string, Cmd>::const_iterator input);
    void Menu();
    void NewGame();
    void ItemShop();
    void Adventure();
    void Hero();
    void Biomes();
};