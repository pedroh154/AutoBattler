#pragma once
#include <list>
#include <random>
#include <Vector>

#include "Battlefield/Tile.h"

struct Tile;
class Character;
class BattleField;
class Player;

class Game
{
public:
    Game(){};
    
    void StartNewMatch();
    void EndMatch();
    
    virtual bool ReadyToEndMatch();
    
private:
    void SetupBattlefield();
    void SetupPlayers();
    void PopulateBattlefield();
    void GameLoop();
    void BeginTurn();
    
    Character* AllocateCharacter(int classIndex, Player* owner, Tile* tile);
    
    BattleField* _battlefield;
    std::vector<Player*> _players;
    std::vector<std::vector<Character*>>* _characters; //heap allocation
    
    
    int _numOfCharPerPlayer = 0;
    int _turnCounter = 0;
    int _defeatedPlayers = 0;

public:
    virtual void OnTurnStarted();
    virtual void OnTurnEnded();
    virtual Player* GetRandomPlayer();
    
    virtual bool IsValidCharacterType(int characterType);
    int GetRandomCharacterType();

    template<typename T>
    void shuffleVector(const std::vector<T>& vector, std::vector<T>& randomizedVector)
    {
        randomizedVector = vector;
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(randomizedVector.begin(), randomizedVector.end(), generator);
    }
};
