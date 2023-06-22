#pragma once
#include <string>

class Game;

struct CharAttributes
{
private:
    float Health = 100.0f;
    float BaseDamage = 30.0f;
    float DamageMultiplier = 1.0f;

public:
    float GetHealth() const
    {
        return Health;
    }

    void SetHealth(float health)
    {
        Health = health;
    }

    float GetBaseDamage() const
    {
        return BaseDamage;
    }

    void SetBaseDamage(float base_damage)
    {
        BaseDamage = base_damage;
    }

    float GetDamageMultiplier() const
    {
        return DamageMultiplier;
    }

    void SetDamageMultiplier(float damage_multiplier)
    {
        DamageMultiplier = damage_multiplier;
    }
};

class Character
{
    friend Game;

protected:
    int _teamNum = -1;

public:
    virtual ~Character() = default;
    Character(int teamNum);
    
    CharAttributes CharacterAttributes;

    virtual std::string GetName() = 0;

    virtual void Move();
    Character* ScanForTarget();

    
    
    int GetTeamNum() const
    {
        return _teamNum;
    }
    
    void SetTeamNum(int teamNum)
    {
        if(teamNum > 0)
            _teamNum = teamNum;
    }

    
};

