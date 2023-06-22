#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
    using Character::Character;

    std::string GetName() override
    {
        return "W" + std::to_string(GetTeamNum());
    }
};
