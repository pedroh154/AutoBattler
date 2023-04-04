#pragma once
#include "Character.h"

class Paladin : public Character
{
public:
    using Character::Character;

    std::string GetStringRepresentation() override
    {
        return "P" + std::to_string(TeamNum);
    }
};
