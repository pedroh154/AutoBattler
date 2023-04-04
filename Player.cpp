#include "Player.h"

Player::Player(int teamNum)
{
    TeamNum = teamNum;
}

void Player::OnTurnStarted()
{
}

bool Player::IsDefeated()
{
    return false;
}
