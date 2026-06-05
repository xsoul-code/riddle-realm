#pragma once
#include <map>
#include <string>

enum class Cmd {
    START,
    END,
    CREDITS,
    MENU,
    NEWGAME,
    ITEMSHOP,
    HERO,
    ADVENTURE,
    L_CMD,
    LOAD,
    WHERE,
    BIOMES
};

enum class CmdCtx { PRE_GAME, MENU, IN_GAME, ALWAYS };

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

    {"cmd", Cmd::L_CMD},
    {"help", Cmd::L_CMD},

    {"load", Cmd::LOAD},

    {"where", Cmd::WHERE},
    {"?", Cmd::WHERE},

    {"shop", Cmd::ITEMSHOP},

    {"inv", Cmd::HERO},

    {"tp", Cmd::BIOMES},

    {"exp", Cmd::ADVENTURE}
};

const std::map<Cmd, CmdCtx> cmdCtxMap {
    {Cmd::START,     CmdCtx::PRE_GAME},
    {Cmd::END,       CmdCtx::ALWAYS},
    {Cmd::CREDITS,   CmdCtx::PRE_GAME},
    {Cmd::L_CMD,     CmdCtx::ALWAYS},
    {Cmd::WHERE,     CmdCtx::ALWAYS},
    {Cmd::MENU,      CmdCtx::MENU},
    {Cmd::NEWGAME,   CmdCtx::MENU},
    {Cmd::LOAD,      CmdCtx::MENU},
    {Cmd::ITEMSHOP,  CmdCtx::IN_GAME},
    {Cmd::HERO,      CmdCtx::IN_GAME},
    {Cmd::ADVENTURE, CmdCtx::IN_GAME},
    {Cmd::BIOMES,    CmdCtx::IN_GAME},
};