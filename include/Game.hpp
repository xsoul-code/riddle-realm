#pragma once
#include <iostream>
#include <string>
#include "GameState.hpp"
#include "GameHUD.hpp"

class Game {
private:
    bool isRunning;
    std::string input;
    bool isInitialized;
    GameState gSt;
    GameHUD gHUD;
public:
    Game();
    ~Game();
    void run();
    void update(std::string ipt);
    void render();
    void commandList();
};
