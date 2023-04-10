#include <cassert>

#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"
#include <iostream>
#include <conio.h>

#include "Types.h"
#include "Battlefield/Grid.h"

int main()
{
    Game* game = new(Game);
    game->StartNewMatch();
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

void Game::GameLoop()
{
    while(true)
    {
        _battlefield->DrawGrid();
        system("pause");
        BeginTurn();
    }
}

void Game::BeginTurn()
{
    for(auto player: _players)
    {
        if(!player->IsDefeated())
        {
            bool validChoice = false;
            
            std::cout << player->GetName() << "'s turn" << std::endl;

            //char choice
            int charTypeChoice = -1;
            while(!validChoice)
            {
                std::cout << "Type your character's class" << std::endl;
                std::cin >> charTypeChoice;

                if(!IsValidCharacterType(charTypeChoice))
                {
                    std::cout << "Invalid character class!" << std::endl;
                    system("pause");
                }
                else
                {
                    validChoice = true;
                }
            }

            validChoice = false;
            
            //coordinates choice
            int rowChoice = -1;
            int colChoice = -1;
            while(!validChoice)
            {
                std::cout << "Type your character's row" << std::endl;
                std::cin >> rowChoice;

                std::cout << "Type your character's column" << std::endl;
                std::cin >> colChoice;

                if(!_battlefield->grid()->IsValidTileCoordinate(rowChoice, colChoice))
                {
                    std::cout << "Invalid coordinates!" << std::endl;
                    system("pause");
                }
                else
                {
                    validChoice = true;
                }
            }
            
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

bool Game::ReadyToEndMatch()
{
    return ( _turnCounter > 100 ) || ( _defeatedPlayers == _players.size() );
}

Player* Game::EndMatch()
{
    return nullptr;
}
