#ifndef EXCS_WELL_H
#define EXCS_WELL_H

#include "Card.h"
#include "../Players/Player.h"

class Well : public Card{
public:
    Well();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};

#endif //EXCS_WELL_H