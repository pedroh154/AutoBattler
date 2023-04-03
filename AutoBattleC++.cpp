#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"

int main()
{
    Game* game = new(Game);
    game->GameLoop();
}

Game::Game()
{
    _battlefield = new(BattleField);
}

void Game::GameLoop()
{
    while(true)
    {
        _turnCounter++;
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
