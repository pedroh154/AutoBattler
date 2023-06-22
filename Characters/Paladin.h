#pragma once
#include "Character.h"

class Paladin : public Character
{
public:
    using Character::Character;

    std::string GetName() override
    {
        return "P" + std::to_string(_teamNum);
    }
};
