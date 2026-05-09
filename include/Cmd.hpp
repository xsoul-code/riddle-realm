#pragma once
#include <map>
#include <algorithm>
#include <string>

enum class Cmd{
    START,
    END,
    CREDITS,
    MENU,
    NEWGAME,
    ITEMSHOP,
    HERO,
    ADVENTURE,
    BIOMES
};

const std::map<std::string, Cmd> cmdMap {
    {"start", Cmd::START},
    {"go", Cmd::START},

    {"end", Cmd::END},
    {"quit", Cmd::END},
    {"exit", Cmd::END},

    {"credits", Cmd::CREDITS},
    {"cred", Cmd::CREDITS},

    {"menu", Cmd::MENU},

    {"new", Cmd::NEWGAME},

    {"shop", Cmd::ITEMSHOP},

    {"inv", Cmd::HERO},

    {"tp", Cmd::BIOMES},

    {"exp", Cmd::ADVENTURE}
};




