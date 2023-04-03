#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"
#include <iostream>

int main()
{
    Game* game = new(Game);
    game->StartNewMatch();
}

void Game::StartNewMatch()
{
    SetupPlayers();
    _battlefield = new(BattleField);
    GameLoop();
}

void Game::SetupPlayers()
{
    int numOfPlayers = 0;

    std::cout << "--- Match configuration ---" << std::endl;
    std::cout << "Enter number of players: " << std::endl;
    std::cin >> numOfPlayers;

    //i = team num
    for(int i = 1; i < numOfPlayers + 1; i++)
    {
        Player* newPlayer = new Player(i);
        _players.push_back(newPlayer);
    }
}

void Game::GameLoop()
{
    while(true)
    {
        _battlefield->DrawGrid();
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
