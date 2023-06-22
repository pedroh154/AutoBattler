#include "Character.h"

Character::Character(Player* owner, Tile* destination)
{
    _owner = owner;
    MyTile = destination;
}

void Character::Move()
{
    //move towards target
    Character* target = ScanForTarget();

    if(target)
        Attack(target);
}

Character* Character::ScanForTarget()
{
    return nullptr;
}

void Character::Attack(Character* character)
{
    int finalDmg = CharacterAttributes.GetBaseDamage() * CharacterAttributes.GetDamageMultiplier();
    
    character->ReceiveDamage(finalDmg);
}

void Character::ReceiveDamage(int damageAmount)
{
    CharacterAttributes.SetHealth(CharacterAttributes.GetHealth() - damageAmount);
    
    if(CharacterAttributes.GetHealth() <= 0)
        Die();
}

void Character::Die()
{
    
}
