#pragma once
#include <iostream>
#include <string>
#include "GameState.hpp"
#include "GameHUD.hpp"
#include "Command.hpp"

class Game {
private:
    bool isRunning;
    std::string input;
    bool isInitialized;
    GameState gSt;
public:
    Game();
    ~Game();
    void run();
    void update(std::string ipt);
    void render();
    void commandList();
    GameState& state()        { return gSt; }
    void markInitialized()    { isInitialized = true; }
    void stop()               { isRunning = false; }
    bool isAvailable(CmdCtx ctx) const;
};
