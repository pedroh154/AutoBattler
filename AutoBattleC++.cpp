#include <cassert>

#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"
#include <iostream>
#include <conio.h>

#include "Types.h"

int main()
{
    Game* game = new(Game);
    game->StartNewMatch();
}

void Game::PopulateBattlefield()
{
    //setup human controlled players' characters
    for(const auto player: _players)
    {
        for(int i = 0; i < _numOfCharPerPlayer; i++)
        {
            int characterType = -1;
            
            while(!IsValidCharacterType(characterType))
            {
                std::cout << "--- PLAYER " << player->TeamNum << " Battlefield Initialization ---" << std::endl;
                std::cout << "Select your character: [1] Paladin, [2] Warrior, [3] Cleric, [4] Archer" << std::endl;
                std::cin >> characterType;

                if(!IsValidCharacterType(characterType))
                {
                    std::cout << "Please type a valid character type" << std::endl;
                }
            }
        }
    }

    system("cls");
    
    //setup cpu players' characters
    for(const auto cpuPlayer: _cpuPlayers)
    {
        std::cout << "--- Initializing CPU " << cpuPlayer->TeamNum << " battlefield ---" << std::endl;
        
        for(int i = 0; i < _numOfCharPerPlayer; i++)
        {
            _battlefield->AllocateCharacter(GetRandomCharacterType(), cpuPlayer->TeamNum);
        }

        system("pause");
    }
}

void Game::StartNewMatch()
{
    SetupPlayers();
    
    _battlefield = new(BattleField);
    _battlefield->Setup();
    
    PopulateBattlefield();
    
    GameLoop();
}

void Game::SetupPlayers()
{
    int numOfPlayers = 0;
    int numOfCpu = 0;
    
    std::cout << "--- Match configuration ---" << std::endl;
    std::cout << "Enter number of players: " << std::endl;
    std::cin >> numOfPlayers;
    
    std::cout << "Enter number of CPU controlled players: " << std::endl;
    std::cin >> numOfCpu;

    std::cout << "Enter number of characters per player: " << std::endl;
    std::cin >> _numOfCharPerPlayer;
    
    const int totalPlayers = numOfCpu + numOfPlayers;
    
    int teamNum = 1;
   
    for(; teamNum < numOfPlayers + 1; teamNum++)
    {
        Player* newPlayer = new Player(teamNum);
        _players.push_back(newPlayer);
    }

    for(; teamNum < totalPlayers + 1; teamNum++)
    {
        Player* newPlayer = new Player(teamNum);
        newPlayer->CpuControlled = true;
        _cpuPlayers.push_back(newPlayer);
    }

    assert((_players.size() + _cpuPlayers.size()) == totalPlayers);

    system("cls");
    std::cout << "Match will start with " << totalPlayers << " players, from which " << numOfCpu << " will be controlled by CPU." << std::endl;
    system("pause");
    system("cls");
}

void Game::BeginTurn()
{
    for(auto player: _players)
    {
        if(!player->IsDefeated())
        {
            player->OnTurnStarted();
        }
    }
}

bool Game::IsValidCharacterType(int characterType)
{
    return characterType > 0 && characterType < Types::CharacterClass::MAX;
}

int Game::GetRandomCharacterType()
{
    srand(time(nullptr));
    return 1 + (rand() % Types::MAX - 1);
}

void Game::GameLoop()
{
    while(true)
    {
        _battlefield->DrawGrid();
        system("pause");
        BeginTurn();
    }
}

bool Game::ReadyToEndMatch()
{
    return ( _turnCounter > 100 ) || ( _defeatedPlayers == _players.size() );
}

Player* Game::EndMatch()
{
    return nullptr;
}
