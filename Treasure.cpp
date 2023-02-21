#include "Treasure.h"

Treasure::Treasure() {
    m_stats.loot = 10;
}
void Treasure::applyEncounter(Player &player) const
{
        player.addCoins(m_stats.loot);
        printTreasureMessage();
}

std::string Treasure::getCardName() const
{
    return "Treasure";
}
