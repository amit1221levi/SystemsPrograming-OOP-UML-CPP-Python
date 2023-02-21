#include "Mana.h"
Mana::Mana()
{
    m_stats.heal = 10;
}

void Mana::applyEncounter(Player &player) const
{
    bool isHealer = (player.getJob() == Jobs::Healer);
    if(isHealer){
        player.heal(m_stats.heal);
    }
    printManaMessage(isHealer);
}

std::string Mana::getCardName() const
{
    return "Mana";
}

