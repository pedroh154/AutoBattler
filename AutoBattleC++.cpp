#include "AutoBattleC++.h"
#include "Player.h"
#include "Battlefield/BattleField.h"

int main()
{
    Game* game = new(Game);
}

Game::Game()
{
    _battlefield = new(BattleField);
}
