#include "Card.h"

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    printCardDetails(os,card.getCardName());
    if(card.isMonster()){
        printMonsterDetails(os, card.m_stats.force ,card.m_stats.hpLossOnDefeat ,card.m_stats.loot,card.isDragon());
    }
    printEndOfCardDetails(os);
    return os;
}

bool Card::isMonster() const
{
    std::string cardName = getCardName();
    if(cardName == "Dragon" || cardName == "Gremlin" || cardName == "Witch"){
        return true;
    }
    return false;
}

bool Card::isDragon() const
{
    if(getCardName() == "Dragon"){
        return true;
    }
    return false;
}
