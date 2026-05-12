#include <iostream>
#include "../include/GameHUD.hpp"

std::string GameHUD::clientName;
int GameHUD::clientLevel;
int GameHUD::clientXP;
int GameHUD::clientXPThresh;

GameHUD::GameHUD() {
    GameHUD::clientName = "none";
    GameHUD::clientLevel = 1;
    GameHUD::clientXP = 0;
    GameHUD::clientXPThresh = 1000;
}

void GameHUD::printGenericInfo() {

}

void GameHUD::setHeroClass() {

}
    
void GameHUD::printBiomeInfo() {

}
    
int GameHUD::getLvlThresh() {

    return 1000;
}