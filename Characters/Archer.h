#pragma once
#include "Character.h"

class Archer : public Character
{
public:
    using Character::Character;

    std::string GetName() override
    {
        return "A" + std::to_string(TeamNum);
    }
};
