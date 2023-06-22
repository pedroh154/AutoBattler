#include "Player.h"
#include "Characters/Character.h"
#include <iostream>

Player::Player(int teamNum)
{
    TeamNum = teamNum;
}

void Player::OnTurnStarted()
{
    for(auto character: MyCharacters)
    {
        character->Move();
    }
}

bool Player::IsDefeated()
{
    return false;
}

void Player::AddCharacter(Character* character)
{
    if(character)
    {
        MyCharacters.push_back(character);
    }
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
