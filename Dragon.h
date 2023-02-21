#ifndef EXCS_DRAGON_H
#define EXCS_DRAGON_H
#include "Card.h"

class Dragon : public Card{
public:
    Dragon();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};

#endif //EXCS_DRAGON_H
