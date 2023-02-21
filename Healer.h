#ifndef EX4_HEALER_H
#define EX4_HEALER_H

#include "Player.h"
class Healer: public Player{
public:
    /**
     * C'tor of Healer class
     * @param name string containing player name
     * @return a new instance of a player with Fighter as class
     */
    explicit Healer(std::string name);
    /**
     *heals the player, Healers get a double amount of HP
     * @param heal - number of HP that will be added
     * @return
     *      void
     */
    void heal(int heal) override;
    /**
    * returns the class of the player
    * @return enum Jobs with the above value
    */
    enum Jobs getJob() const override;
};

#endif //EX4_HEALER_H