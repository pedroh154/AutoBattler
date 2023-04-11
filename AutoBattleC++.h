﻿#pragma once
#include <list>

class Character;
class BattleField;
class Player;

class Game
{
public:
    Game(){};
    void StartNewMatch();
    Player* EndMatch();

private:
    void SetupBattlefield();
    void SetupPlayers();
    void PopulateBattlefield();
    void GameLoop();
    void BeginTurn();
    bool ReadyToEndMatch();
    
    Character* AllocateCharacter(int classIndex, int teamNum);
    
    BattleField* _battlefield;
    std::list<Player*> _players;
    
    int _numOfCharPerPlayer = 0;
    int _turnCounter = 0;
    int _defeatedPlayers = 0;

public:
    bool IsValidCharacterType(int characterType);
    int GetRandomCharacterType();
};
