#pragma once
#include "Character.h"

class Cleric : public Character
{
public:
    using Character::Character;

    std::string GetStringRepresentation() override
    {
        return "C" + std::to_string(TeamNum);
    }
};
