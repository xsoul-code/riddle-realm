#include "../include/Command.hpp"
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Tools.hpp"
#include <iostream>

const std::vector<Command>& commandTable() {
    static const std::vector<Command> table = {
        { {"start","go"}, CmdCtx::PreGame, "Start the game",
          [](Game& g){ g.markInitialized(); g.state().Menu(); } },

        { {"end","quit","exit"}, CmdCtx::Always, "Quit",
          [](Game& g){ clearScreen(); std::cout << "Exiting...\n"; g.stop(); } },

        { {"credits","cred"}, CmdCtx::PreGame, "Credits",
          [](Game&){ std::cout << "Credits\n"; } },

        { {"new"},   CmdCtx::Menu,   "New adventure",   [](Game& g){ g.state().NewGame();  } },
        { {"load"},  CmdCtx::Menu,   "Load a game",     [](Game&){ std::cout << "LOAD - coming soon!\n"; } },
        { {"shop"},  CmdCtx::InGame, "Item shop",       [](Game& g){ g.state().ItemShop();  } },
        { {"inv"},   CmdCtx::InGame, "View your hero",  [](Game& g){ g.state().Hero();      } },
        { {"exp"},   CmdCtx::InGame, "Go on an adventure", [](Game& g){ g.state().Adventure(); } },
        { {"tp"},    CmdCtx::InGame, "Travel biomes",   [](Game& g){ g.state().Biomes();    } },

        { {"cmd","help"}, CmdCtx::Always, "List commands", [](Game& g){ g.commandList(); } },
        { {"where","?"},  CmdCtx::Always, "Where am I",    [](Game& g){ g.state().displayCurrState(); } },
    };
    return table;
}

const Command* findCommand(const std::string& input) {
    for (const auto& c : commandTable())
        for (const auto& n : c.names)
            if (n == input) return &c;
    return nullptr;   
}