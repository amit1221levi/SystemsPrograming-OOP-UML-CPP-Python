#include "Player.h"
#include "utilities.h"

Player::Player(std::string name, int maxHP, int force) :
    m_level(DEFAULT_LEVEL),
    m_coins(DEFAULT_COINS),
    m_name(name)
{
    if(maxHP > 0 ) {
        this-> m_maxHP = maxHP;
        this-> m_hp = maxHP;
    }
    else {
        this-> m_maxHP = DEFAULT_MAX_HP;
        this->m_hp = DEFAULT_MAX_HP;
    }
    if(force > 0) {
        this-> m_force = force;
    }
    else {
        this-> m_force = DEFAULT_FORCE;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_hp, m_coins);
}

bool Player::levelUp()
{
     if(m_level < MAX_LEVEL) {
        m_level++;
        return true;
     }
     return false;
}

int Player::getLevel() const
{
    return m_level;
}

bool Player::buff(int forcePoints)
{
    if(forcePoints < 0) {
        return false;
    }
    m_force += forcePoints;
    return true;
}

bool Player::heal(int hp)
{
    if(m_hp == m_maxHP || hp < 0) {
        return false;
    }
    if(m_hp >= (m_maxHP - hp)) {
        m_hp = m_maxHP;
        return true;
    }
    m_hp += hp;
    return true;
}

bool Player::damage(int damage) 
{
    if(damage < 0) {
        return false;
    }
    if(damage > m_hp) {
        m_hp = 0;
        return true;
    }
    m_hp -= damage;
    return true;
}

bool Player::isKnockedOut() const
{
    return m_hp == 0;
}

bool Player::addCoins(int coins)
{
    if(coins < 0) {
        return false;
    }
    m_coins += coins;
    return true;
}

bool Player::pay(int coins)
{
    if(m_coins < coins) {
        return false;
    }
    if(coins <= 0) {
        return true;
    }
    m_coins -= coins;
    return true;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}
