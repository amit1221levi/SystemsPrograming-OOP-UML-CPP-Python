#include "Warrior.h"

using namespace std;

Warrior::Warrior(string name) : Player(name)
{}

int Warrior::getAttackStrength() const
{
    return m_force*2+m_level;
}

enum Jobs Warrior::getJob() const
        {
    return Jobs::Warrior;
}