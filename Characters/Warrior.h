#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
    using Character::Character;

    std::string GetStringRepresentation() override
    {
        return "W" + std::to_string(TeamNum);
    }
};
