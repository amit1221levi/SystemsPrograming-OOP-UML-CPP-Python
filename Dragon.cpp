#include "Dragon.h"
#include "../utilities.h"
Dragon::Dragon()
{
    m_stats.force = 25;
    m_stats.loot = 1000;
    m_stats.hpLossOnDefeat = 100;
}

void Dragon::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_stats.force){
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getPlayerName(),"Dragon");
    }
    else{
        player.dragonDamage();
        printLossBattle(player.getPlayerName(),"Dragon");
    }
}

std::string Dragon::getCardName() const
{
    return "Dragon";
}
