#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHP)
{
    if(maxHP <= 0){
        throw InvalidArgument();
    }
    m_healthPoints = maxHP;
    m_maxHP = maxHP;
}

HealthPoints& HealthPoints::operator+=(int hpAmount)
{
    m_healthPoints += hpAmount;
    if(m_healthPoints > m_maxHP) {
        m_healthPoints = m_maxHP;
    }
    else if(m_healthPoints < 0) {
        m_healthPoints = 0;
    }
    return *this;
}

HealthPoints operator+(const HealthPoints& hp, int hpAmount)
{
    HealthPoints result(hp);
    return (result+= hpAmount);
}

HealthPoints operator+(int hpAmount, const HealthPoints& hp)
{
    return hp + hpAmount;
}

HealthPoints& HealthPoints::operator-=(int hpAmount)
{
    return *this+= -hpAmount;
}

HealthPoints operator-(const HealthPoints& hp, int hpAmount)
{
    HealthPoints result(hp);
    return (result-= hpAmount);
}

bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_healthPoints == healthPoints2.m_healthPoints;
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 == healthPoints2);
}

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_healthPoints < healthPoints2.m_healthPoints;
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints2 < healthPoints1;
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 > healthPoints2);
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 < healthPoints2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_healthPoints << "(" << hp.m_maxHP << ")";
    return os;
}