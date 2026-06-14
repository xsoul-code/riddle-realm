#pragma once 
#include <string>
#include "GameHUD.hpp"
#include "Cmd.hpp"

enum class Screen {Menu=0, NewGame=1, ItemShop=2, Adventure=3, Hero=4, Biomes=5};

class GameState { 
private:
    static Screen state;
public:
    static Screen getState() { return state; }
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