#pragma once
#include <string>
#include <vector>
#include <functional>

class Game; // Forward declaration

enum class CmdCtx {PreGame, Menu, InGame, Always};

struct Command {
    std::vector<std::string> names; // Aliases
    CmdCtx ctx;
    std::string help;
    std::function<void(Game&)> run;
};

const std::vector<Command>& commandTable();
const Command* findCommand(const std::string& input);