#ifndef EX4_NINJA_H
#define EX4_NINJA_H

#include "Player.h"
#include "../utilities.h"

class Ninja: public Player{
public:
    /**
     * C'tor of Ninja class
     * @param name string containing player name
     * @return a new instance of a player with Ninja as class
     */
    explicit Ninja(std::string name);
    /**
     * add coins to the player,Ninja get double the coins
     *@param coins - number of coins that will be added
     * @return
     *      void
     */
    void addCoins(int coins) override;
    /**
     * returns the class of the player
     * @return enum Jobs with the above value
     */
    enum Jobs getJob() const override;
};

#endif //EX4_NINJA_H