#include <iostream>
#include <map>
#include "../include/GameHUD.hpp"
#include "../include/GameState.hpp"


std::map<int, Biomes> biomeMap = {
    {1, Biomes::Woods},
    {2, Biomes::Lands},
    {3, Biomes::CastleLand}
};

std::map<Biomes, std::string> biomeNameMap = {
    {Biomes::Woods, "Woods"},
    {Biomes::Lands, "Lands"},
    {Biomes::CastleLand, "CastleLand"}
};

GameHUD::GameHUD() {
    GameHUD::clientName = "Not Named Yet";
    GameHUD::clientLevel = 1;
    GameHUD::clientXP = 0;
    GameHUD::clientXPThresh = 1000;
    GameHUD::biome = 1;
}

void GameHUD::printGenericInfo() {
    std::cout << "The name: " << clientName << std::endl;
    std::cout << "Lvl: " << clientLevel << " XP: " << clientXP << "/" << clientXPThresh << std::endl;
    auto biomeFind = biomeMap.find(biome);
    if(biomeFind != biomeMap.end()) {
        auto biomeName = biomeNameMap.find(biomeFind->second);
        std::cout << "You are in biome: " << biomeName->second << std::endl;
    }
    else {
        std::cout << "Please choose your biome destination" << std::endl;
    }
        
}

void GameHUD::setHeroClass() {

}
    
void GameHUD::printBiomeInfo() {

}
    
int GameHUD::getLvlThresh() {

    return 1000;
}