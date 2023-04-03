#pragma once
#include <list>

#include "Player.h"

class BattleField;

class Game
{
public:
    Game(){};
    void StartNewMatch();
    void GameLoop();
    void SetupPlayers();
    
private:
    BattleField* _battlefield;
    std::list<Player*> _players;
    
    int _turnCounter = 0;
    int _defeatedPlayers = 0;

public:
    bool ReadyToEndMatch();

    //returns match winner
    Player* EndMatch();
};
