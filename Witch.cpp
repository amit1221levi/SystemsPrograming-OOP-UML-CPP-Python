#include "Witch.h"

Witch::Witch()
{
    m_stats.force = 11;
    m_stats.loot = 2;
    m_stats.hpLossOnDefeat = 10;
}

void Witch::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_stats.force){
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getPlayerName(),"Witch");
    }
    else{
        player.damage(m_stats.hpLossOnDefeat);
        player.vampireDamage();
        printLossBattle(player.getPlayerName(),"Witch");
    }
}

std::string Witch::getCardName() const
{
    return "Witch";
}