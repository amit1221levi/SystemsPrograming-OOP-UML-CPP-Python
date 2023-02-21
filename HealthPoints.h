#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#include <iostream>

class HealthPoints {

public:

    static const int DEFAULT_MAX_HP = 100;

    /**
     * C'tor of HealthPoints:
     * @param MaxHP - the max level of HP the HealthPoints is able to have
     *
     * @result
     *      a HealthPoints in Mtmchkin game
     */
    HealthPoints(int maxHP=DEFAULT_MAX_HP);

    /**
    * Arithmetic operators - add, subtruct and negative
    * @return this
    */
    HealthPoints& operator+=(int);
    HealthPoints& operator-=(int);

    /**
     * explicitly telling the compiler to use the default methods
     */
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints& other) = default;

    /**
     * an exception to be thrown when an invalid argument is
     * passed to a method
     */
    class InvalidArgument{};

private:
    int m_healthPoints;
    int m_maxHP;

    /**
    * Boolean operators
    * compares two instances of HealthPoints
    * @return true if condition is met, otherwise false
    */
   friend bool operator==(const HealthPoints&, const HealthPoints&);
   friend bool operator<(const HealthPoints&, const HealthPoints&);
    /**
    * Output operator - formatted as <currentValue>(<maxValue>)
    * @return ostream type reference that includes this HealthPoints details
    */
   friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
};

/**
* Non-member arithmatic operators
* @return new HealthPoints instance after adding or subtructing
*/
HealthPoints operator+(const HealthPoints&, int);
HealthPoints operator+(int, const HealthPoints&);
HealthPoints operator-(const HealthPoints&, int);

/**
* Non-member Boolean operators
* compares two instances of HealthPoints using the member operators
* @return true if condition is met, otherwise false
*/
bool operator!=(const HealthPoints&, const HealthPoints&);
bool operator>=(const HealthPoints&, const HealthPoints&);
bool operator>(const HealthPoints&, const HealthPoints&);
bool operator<=(const HealthPoints&, const HealthPoints&);


#endif //EX3_HEALTHPOINTS_H