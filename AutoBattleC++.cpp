#include <cassert>
#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"
#include <iostream>
#include "Types.h"
#include "Battlefield/Grid.h"
#include "Characters/Archer.h"
#include "Characters/Cleric.h"
#include "Characters/Paladin.h"
#include "Characters/Character.h"
#include "Characters/Warrior.h"

int main()
{
    Game* game = new(Game);
    game->StartNewMatch();
}

void Game::StartNewMatch()
{
    SetupBattlefield();
    SetupPlayers();
    PopulateBattlefield();
    
    GameLoop();
}

void Game::SetupBattlefield()
{
    int sizeX = 0;
    int sizeY = 0;

    while (sizeX <= 0 || sizeY <= 0)
    {
        std::cout << "--- Battlefield configuration ---" << std::endl;
        std::cout << "Enter number of rows: " << std::endl;
        std::cin >> sizeX;

        std::cout << "Enter number of columns: " << std::endl;
        std::cin >> sizeY;
    }
    
    _battlefield = new BattleField(sizeX, sizeY);

    system("cls");
    std::cout << "Battlefield size will be " << sizeX << " by " << sizeY << ", with " << sizeX * sizeY << " total tiles" << std::endl;
    system("pause");
    system("cls");
    
    _battlefield->DrawGrid();
    system("pause");
    system("cls");
}

void Game::SetupPlayers()
{
    int numOfPlayers = 0;
    int numOfCpu = 0;
    
    std::cout << "--- Match configuration ---" << std::endl;
    std::cout << "Enter number of human players: " << std::endl;
    std::cin >> numOfPlayers;
    
    std::cout << "Enter number of CPU controlled players: " << std::endl;
    std::cin >> numOfCpu;

    std::cout << "Enter number of characters per player: " << std::endl;
    std::cin >> _numOfCharPerPlayer;
    
    const int totalPlayers = numOfCpu + numOfPlayers;

    _characters = new std::vector<std::vector<Character*>>(totalPlayers);
    
    //avoid team 0
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
        _players.push_back(newPlayer);
    }

    assert((_players.size()) == totalPlayers);

    system("cls");
    std::cout << "Match will start with " << totalPlayers << " players, from which " << numOfCpu << " will be controlled by CPU." << std::endl;
    system("pause");
    system("cls");
}

void Game::PopulateBattlefield()
{
    int charTypeChoice = -1;
    int rowChoice = -1;
    int colChoice = -1;
    int numOfInitializedChars;
    
    for(auto player: _players)
    {
        numOfInitializedChars = 0;

        system("cls");
        std::cout << player->GetName() << ": POPULATE YOUR BATTLEFIELD" << std::endl;
        
        _battlefield->DrawGrid();
        
        if(!player->CpuControlled)
        {
            while(numOfInitializedChars != _numOfCharPerPlayer)
            {
                //pick player choices
                
                //char choice
                bool validCharChoice = false;
                while(!validCharChoice)
                {
                    std::cout << "Type your character's class" << std::endl;
                    std::cin >> charTypeChoice;

                    if(!IsValidCharacterType(charTypeChoice))
                    {
                        std::cout << "Invalid character class!" << std::endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        validCharChoice = true;
                    }
                }
                

                //coordinates choice
                bool validCoordChoice = false;
                bool unoccupiedCoordChoice = false;
                while(!validCoordChoice || !unoccupiedCoordChoice)
                {
                    std::cout << "Type your character's row" << std::endl;
                    std::cin >> rowChoice;

                    std::cout << "Type your character's column" << std::endl;
                    std::cin >> colChoice;

                    //valid coordinate?
                    if(_battlefield->GetGrid()->IsValidTileCoordinate(rowChoice, colChoice))
                    {
                        validCoordChoice = true;

                        //coordinate unoccupied?
                        if(!_battlefield->GetGrid()->_tiles[rowChoice - 1][colChoice - 1]->GetCurrentCharacter())
                        {
                            unoccupiedCoordChoice = true;
                        }
                        else
                        {
                            std::cout << "This tile is already occupied!" << std::endl;
                            system("pause");
                            system("cls");
                        }    
                    }
                    else
                    {
                        std::cout << "Invalid coordinate!" << std::endl;
                        system("pause");
                        system("cls");
                    }
                }

                Character* newChar = AllocateCharacter(charTypeChoice, player, _battlefield->GetGrid()->_tiles[rowChoice - 1][colChoice - 1]);
                
                numOfInitializedChars++;

                system("cls");
                _battlefield->DrawGrid();
                system("pause");
            }
        }
            
        
        else
        {
            std::cout << player->GetName() << " is making choices..." << std::endl;

            while(numOfInitializedChars != _numOfCharPerPlayer)
            {
                charTypeChoice = GetRandomCharacterType();
                rowChoice = _battlefield->GetRandomRow();
                colChoice = _battlefield->GetRandomCol();
                
                Character* newChar = AllocateCharacter(charTypeChoice, player, _battlefield->GetGrid()->_tiles[rowChoice][colChoice]);
                
                numOfInitializedChars++;

                std::cout << "inserted " << newChar->GetName() << " @ " << rowChoice << ", " << colChoice << std::endl;
            }
            
            system("pause");
            system("cls");
        }
    }
}

void Game::GameLoop()
{
    while(true)
    {
        if(ReadyToEndMatch())
        {
            EndMatch();    
        }
        
        BeginTurn();
        system("pause");
        
        _battlefield->DrawGrid();
        system("pause");
    }
}

void Game::BeginTurn()
{
    _turnCounter++;
    std::cout << "TURN [" << _turnCounter << "]" << std::endl;

    OnTurnStarted();
}

bool Game::ReadyToEndMatch()
{
    return ( _turnCounter > 100 ) || ( _defeatedPlayers >= _players.size() );
}

void Game::EndMatch()
{
}

void Game::OnTurnStarted()
{
    assert(_players.size() > 0);

    //determine this turns' order
    std::vector<Player*> players;
    shuffleVector(_players, players);
    
    for(auto player: players)
    {
        player->OnTurnStarted();
    }
}

void Game::OnTurnEnded()
{
}

Player* Game::GetRandomPlayer()
{
    for(int i = 0; i < _players.size(); i++)
    {
        return _players[_battlefield->GetRandomInt(0, _players.size())];
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

Character* Game::AllocateCharacter(int classIndex, Player* owner, Tile* tile)
{
    assert(owner);
    assert(tile->GetCurrentCharacter() == nullptr);
    
    Character* allocatedChar = nullptr;
    
    switch(classIndex)
    {
    case 1:
        allocatedChar = new Paladin(owner, tile);
        break;
    case 2:
        //allocatedChar = new Warrior(owner,tile);
        break;
    case 3:
         //allocatedChar = new Cleric(owner, tile);
        break;
    case 4:
        //allocatedChar = new Archer(owner, tile);
        break;
    default:
        //allocatedChar = new Paladin(owner, tile);
        break;
    }

    owner->AddCharacter(allocatedChar);
    
    return allocatedChar;
}


