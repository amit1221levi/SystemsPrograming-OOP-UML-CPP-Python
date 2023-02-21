#include "Well.h"


Well::Well()
{
    m_stats.hpLossOnDefeat = 10;
}

void Well::applyEncounter(Player &player) const
{
    bool isNinja = (player.getJob() == Jobs::Ninja);
    if(!isNinja){
        player.damage(m_stats.hpLossOnDefeat);
    }
    printWellMessage(isNinja);
}

std::string Well::getCardName() const
{
    return "Well";
}