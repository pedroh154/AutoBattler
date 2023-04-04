#pragma once
#include <list>

#include "Player.h"

class BattleField;

class Game
{
public:
    Game(){};
    void PopulateBattlefield();
    void StartNewMatch();
    void GameLoop();
    void SetupPlayers();
    void BeginTurn();

    bool IsValidCharacterType(int characterType);

    int GetRandomCharacterType();
    
private:
    BattleField* _battlefield;
    std::list<Player*> _players;
    std::list<Player*> _cpuPlayers;
    int _numOfCharPerPlayer = 0;
    
    int _turnCounter = 0;
    int _defeatedPlayers = 0;

public:
    bool ReadyToEndMatch();

    //returns match winner
    Player* EndMatch();
};
