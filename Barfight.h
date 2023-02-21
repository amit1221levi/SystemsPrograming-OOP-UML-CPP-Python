#ifndef EXCS_BARFIGHT_H
#define EXCS_BARFIGHT_H

#include "Card.h"
#include "../Players/Player.h"

class Barfight : public Card{
public:
    Barfight();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;

};

#endif //EXCS_BARFIGHT_H
