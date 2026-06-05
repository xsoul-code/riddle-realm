#pragma once 
#include <string>
#include "GameHUD.hpp"
#include "Cmd.hpp"

class GameState { 
private:
    static int state;
public:
    static int getState() { return state; }
    GameHUD HUD;
    GameState();
    ~GameState() = default;
    void process(std::map<std::string, Cmd>::const_iterator input);
    void Menu();
    void NewGame();
    void ItemShop();
    void Adventure();
    void Hero();
    void Biomes();
    void displayCurrState();
};