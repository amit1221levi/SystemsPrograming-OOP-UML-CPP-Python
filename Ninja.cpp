#include "Ninja.h"

Ninja::Ninja(std::string name) : Player(name)
{}

void Ninja::addCoins(int coins)
{
    Player::addCoins(2*coins);
}

enum Jobs Ninja::getJob() const
{
    return Jobs::Ninja;
}