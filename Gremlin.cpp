#include "Gremlin.h"
#include "../utilities.h"

Gremlin::Gremlin()
{
    m_stats.force = 5;
    m_stats.loot = 2;
    m_stats.hpLossOnDefeat = 10;
}

void Gremlin::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_stats.force){
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getPlayerName(),"Gremlin");
    }
    else{
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getPlayerName(),"Gremlin");
    }
}

std::string Gremlin::getCardName() const
{
    return "Gremlin";
}


