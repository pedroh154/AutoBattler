#include "Player.h"

#include <iostream>

Player::Player(int teamNum)
{
    TeamNum = teamNum;
}

void Player::OnTurnStarted()
{
    if(CpuControlled)
    {
        
    }
    else
    {
        
    }
}

bool Player::IsDefeated()
{
    return false;
}

std::string Player::GetName()
{
    std::string name = "Player " + std::to_string(TeamNum);

    if(CpuControlled)
    {
        name.append(" (CPU)");
    }

    return name;
}
