#ifndef EXCS_MANA_H
#define EXCS_MANA_H

#include "Card.h"

class Mana:public Card{
public:
    Mana();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
private:
};

#endif //EXCS_MANA_H
