#ifndef EXCS_MERCHANT_H
#define EXCS_MERCHANT_H
#include "Card.h"

class Merchant:public Card{
public:
    static const int BUY_NOTHING = 0;
    static const int BUY_HEALTH_POTION = 1;
    static const int BUY_FORCE_BOOST = 2;
    static const int HEALTH_POTION_COST = 5;
    static const int FORCE_BOOST_COST = 10;

    void applyEncounter(Player &player) const override;
    std::string getCardName() const override;
};
#endif //EXCS_MERCHANT_H