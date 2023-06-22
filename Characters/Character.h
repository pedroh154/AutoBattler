#pragma once
#include <string>
#include "../Player.h"
#include "../Utils.h"

struct Tile;
class Game;

struct CharAttributes
{
    
private:
    float _health = 100.0f;
    float _baseDamage = 30.0f;
    float _damageMultiplier = 1.0f;
    float _maxHealth = 100.0f;

public:
    float GetHealth() const
    {
        return _health;
    }

    void SetHealth(float health)
    {
        _health = Utils::Clamp<float>(0.0f, _maxHealth, health);
    }

    float GetBaseDamage() const
    {
        return _baseDamage;
    }

    void SetBaseDamage(float base_damage)
    {
        _baseDamage = base_damage;
    }

    float GetDamageMultiplier() const
    {
        return _damageMultiplier;
    }

    void SetDamageMultiplier(float damage_multiplier)
    {
        _damageMultiplier = damage_multiplier;
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

