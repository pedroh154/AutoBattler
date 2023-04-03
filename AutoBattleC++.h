#pragma once
#include "Player.h"

class BattleField;

class Game
{
public:
    Game();

private:
    Player _players[2];
    BattleField* _battlefield;
};
