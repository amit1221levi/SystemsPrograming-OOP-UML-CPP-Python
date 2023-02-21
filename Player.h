#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <string>

class Player {
public:

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE  = 5;
    static const int DEFAULT_LEVEL = 1;
    static const int DEFAULT_COINS  = 0;
    static const int MAX_LEVEL  = 10;
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
    Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /*
     * prints the info of the player -
     *      name,force,HP,level and number of coins
     */
    void printInfo() const;

    /*
     *levels up the player
     * @return
     *      true if leveled up
     *      false otherwise
     */
    bool levelUp();

    /*
     *returns the level of the player
     *@return
     *      int with the value of the level
     */
    int getLevel() const;

    /*
     *adds force to the player
     * @param force - number of points that will be added to the force
     * @return
     *      true if the buff was given
     *      false otherwise
     */
    bool buff(int forcePoints);

    /*
     *heals the player
     * @param heal - number of HP that will be added
     * @return
     *      true if the health points was given
     *      false otherwise
     */
    bool heal(int hp);

    /*
     * inflicts damage to the player
     *@param damageHP - number of HP points that will subtract due to damage
     * @return
     *      true if the damage was dealt
     *      false otherwise
     */
    bool damage(int damage);

    /*
     *checks if a player is knockedOut (has 0 HP)
     *@return
     *      true if the player is knocked out
     *      false if he isn't
     */
    bool isKnockedOut() const;

    /*
     * add coins to the player
     *@param coins - number of coins that will be added
     * @return
     *      true if the coins was given
     *      false othewise
     */
    bool addCoins(int coins);

    /*
     *payment method - subtracts coins from player
     *@param pay - number of coins that will subtract
     * @return
     *      true if payment completed successfully
     *      false if the player didn't have enough coins
     */
    bool pay(int coints);

    /*
     *returns the attack strength of the player (force + level)
     *@return
     *      int with the above value
     */
    int getAttackStrength() const;

    /*
     *explicitly telling the compiler to use the default methods
     */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


private:
    int m_maxHP;
    int m_hp;
    int m_force;
    int m_level;
    int m_coins;
	std::string m_name;

};


#endif //EX2_PLAYER_H