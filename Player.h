
#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <iostream>
#include <string>

enum class Jobs{Healer,Ninja,Warrior};

class Player {
public:

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;
    static const int START_LEVEL = 1;
    static const int MAX_LEVEL = 10;

    /*
     * C'tor of Player:
     *
     * @param name - the name of the player
     * @param MaxHP - the max level of HP the player is able to have
     * @param force - the force of the player
     *
     * @result
     *      a player in Mtmchkin game
     *
     */
    explicit Player(std::string name);

    /*
     *levels up the player
     * @return
     *      void
     */
    void levelUp();

    /*
     *adds force to the player
     * @param force - number of points that will be added to the force
     * @return
     *      void
     */
    void buff(int force);

    /*
     *heals the player
     * @param heal - number of HP that will be added
     * @return
     *      void
     */
    virtual void heal(int heal);

    /*
     * inflicts damage to the player
     *@param damageHP - number of HP points that will subtract due to damage
     *@return
     *      void
     */
    void damage(int damageHP);

    /*
     * add coins to the player
     *@param coins - number of coins that will be added
     * @return
     *      void
     */
    virtual void addCoins(int coins);

    /*
     *payment method - subtracts coins from player
     *@param pay - number of coins that will subtract
     * @return
     *      true if payment completed successfully
     *      false if the player didn't have enough coins
     */
    bool pay(int pay);

    /*
     *checks if a player is knockedOut (has 0 HP)
     *@return
     *      true if the player is knocked out
     *      false if he isn't
     */
    bool isKnockedOut() const;

    /*
     *returns the attack strength of the player (force + level)
     *@return
     *      int with the above value
     */
    virtual int getAttackStrength() const;

    /**
     * returns the number of coins a player has
     * @return int with the above value
     */
    int getNumOfCoins() const;

    /**
     * inflicts vampire damage to player
     */
    void vampireDamage();

    /**
     * inflicts dragon damage to player
     */
    void dragonDamage();

    /**
     * checks if the player won the game
     * @return bool with the above value
     */
    bool isWinner() const;

    /**
     * returns the class of the player
     * @return enum Jobs with the above value
     */
    virtual enum Jobs getJob() const = 0;

    /**
     * return the name of the player
     * @return string with the above value
     */
    std::string getPlayerName() const;

    Player(const Player &) = default;
    ~Player() = default;
    Player &operator=(const Player &other) = default;

protected:
    int m_level;
    int m_force;
    int m_HP;
    int m_coins;
    std::string m_name;
private:
    int m_maxHP;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

};


#endif //EX4_PLAYER_H
