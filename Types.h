#pragma once
#include <string>

class Types
{
public:
    enum CharacterClass
    {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4,
        MAX = 5
    };

    static std::string GetClassNameByCharacter(CharacterClass charClass)
    {
        std::string name;
        
        switch(charClass)
        {
            case Paladin:
                name = "Paladin";
            break;
            case Warrior:
                name = "Warrior";
            break;
            case Cleric:
                name = "Cleric";
            break;
            case Archer:
                name = "Archer";
            break;
            default:
                name = "FIX_ME_CLASS_NAME";
        }

        return name;
    }
};

