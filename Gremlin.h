#ifndef EXCS_GREMLIN_H
#define EXCS_GREMLIN_H

#include "Card.h"

class Gremlin : public Card{
public:
    Gremlin();
    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};

#endif //EXCS_GREMLIN_H
