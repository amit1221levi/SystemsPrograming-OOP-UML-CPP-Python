

#include "Player.h"
#include "../utilities.h"

Player::Player(std::string name) :
    m_level(START_LEVEL),
    m_force(DEFAULT_FORCE),
    m_HP(DEFAULT_MAX_HP),
    m_coins(DEFAULT_COINS),
    m_name(move(name)),
    m_maxHP(DEFAULT_MAX_HP)
{}

void Player::heal(int heal)
{
    if(heal < 0){
        heal = 0;
    }
    m_HP += heal;
    if(m_maxHP < m_HP){
        m_HP = m_maxHP;
    }
}

void Player::levelUp()
{
    if(m_level < 10){
        m_level++;
    }
}

void Player::buff(int force)
{
    if(force < 0){
        force = 0;
    }
    m_force += force;
}

void Player::damage(int damage)
{
    if(damage < 0){
        damage = 0;
    }
    m_HP -= damage;
    if(m_HP < 0){
        m_HP = 0;
    }
}

void Player::addCoins(int coins)
{
    if(coins < 0){
        coins = 0;
    }
    m_coins += coins;
}

bool Player::pay(int pay)
{
    if (pay < 0){
        pay = 0;
    }
    if(m_coins - pay < 0){
        return false;
    }
    else {
        m_coins -= pay;
        return true;
    }
}

bool Player::isKnockedOut() const
{
    if(m_HP == 0){
        return true;
    }
    return false;
}

bool Player::isWinner() const
{
    if(m_level == MAX_LEVEL){
        return true;
    }
    else{
        return false;
    }
}

int Player::getAttackStrength() const
{
    return m_level + m_force;
}

void Player::vampireDamage()
{
    if(m_force > 0){
        m_force--;
    }
}

void Player::dragonDamage()
{
    m_HP = 0;
}

int Player::getNumOfCoins() const
{
    return m_coins;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    std::string jobStr;
    enum Jobs job = player.getJob();
    if (job == Jobs::Healer){
        jobStr = "Healer";
    }
    else if(job == Jobs::Warrior){
        jobStr = "Warrior";
    }
    else if(job == Jobs::Ninja){
        jobStr = "Ninja";
    }
    printPlayerDetails(std::cout,player.m_name,jobStr,player.m_level,player.m_force
            ,player.m_HP,player.m_coins);
    return os;
}

std::string Player::getPlayerName() const
{
    return m_name;
}



