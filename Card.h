#ifndef EX4_Card_H
#define EX4_Card_H


#include <string>
#include "../Players/Player.h"
#include "../Players/Healer.h"
#include "../Players/Warrior.h"
#include "../Players/Ninja.h"
#include "../utilities.h"

struct CardStats{
    int force;  // The force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of hp you lose when losing the battle
    int heal; // The amount of HP you get when buying a "HEAL" card

    explicit CardStats(int force = 0, int hpLoss = 0,  int heal = 0, int loot = 0)
    {
        this->force = force;
        this->hpLossOnDefeat = hpLoss;
        this->heal = heal;
        this->loot = loot;
    }
};


class Card {
public:
    virtual void applyEncounter(Player& player) const = 0;
    virtual std::string getCardName() const = 0;
    bool isMonster() const;
    bool isDragon() const;
    Card() = default;
    Card(Card& card) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;
protected:
    CardStats m_stats;
private:
    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};

#endif //EX4_Card_H