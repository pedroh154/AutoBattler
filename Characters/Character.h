#pragma once
#include <string>
#include "../Utils.h"
#include "../Player.h"

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
        int clampedValue = Utils::clamp(0, Health, health);
        Health = clampedValue;
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

public:
    Character(Player* owner, Tile* tile);
    virtual ~Character() = default;
    
    virtual void Move();
    virtual Character* ScanForTarget();
    virtual void Attack(Character* character);
    virtual void ReceiveDamage(int damageAmount);
    virtual void Die();

    virtual std::string GetName() = 0;

    int GetTeamNum() const
    {
        return _owner ? _owner->TeamNum : -1;
    }

    Tile* GetTile() const
    {
        return MyTile;
    }
    
protected:
    Tile* MyTile = nullptr;

    CharAttributes CharacterAttributes;
    
private:
    Player* _owner;
};

