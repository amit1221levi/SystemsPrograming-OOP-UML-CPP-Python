#include "Healer.h"

Healer::Healer(std::string name) : Player(name)
{}

void Healer::heal(int heal)
{
    Player::heal(2*heal);
}

enum Jobs Healer::getJob() const
{
    return Jobs::Healer;
}