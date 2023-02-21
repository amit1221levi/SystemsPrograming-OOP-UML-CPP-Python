#include "Barfight.h"

Barfight::Barfight()
{
    m_stats.hpLossOnDefeat = 10;
}

void Barfight::applyEncounter(Player &player) const
{
    bool isWarrior = (player.getJob() == Jobs::Warrior);
    if(!isWarrior) {
        player.damage(m_stats.hpLossOnDefeat);
    }
    printBarfightMessage(isWarrior);
}

std::string Barfight::getCardName() const
{
    return "Barfight";
}
