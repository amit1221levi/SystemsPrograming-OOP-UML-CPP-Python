#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H

#include "Player.h"
#include "../utilities.h"

class Warrior:public Player{
public:
    /**
     * C'tor of Warrior class
     * @param name string containing player name
     * @return a new instance of a player with Warrior as class
     */
    explicit Warrior(std::string name);
    /**
     *returns the attack strength of the player (2*force + level)
     *@return
     *      int with the above value
     */
    int getAttackStrength() const override;
    /**
     * returns the class of the player
     * @return enum Jobs with the above value
     */
    enum Jobs getJob() const override;
};

#endif //EX4_WARRIOR_H