#ifndef EXCS_TREASURE_H
#define EXCS_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    Treasure();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};
#endif //EXCS_TREASURE_H