#ifndef EXCS_WITCH_H
#define EXCS_WITCH_H
#include "Card.h"

class Witch : public Card{
public:
    Witch();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};
#endif //EXCS_WITCH_H
