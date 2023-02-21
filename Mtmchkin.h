#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <deque>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include "Players/Player.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "utilities.h"

class Mtmchkin{

public:
    
    static const int MIN_SIZE_OF_DECK = 5;

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin& operator=(const Mtmchkin& mtmchkin) = delete;
    Mtmchkin(const Mtmchkin&) = delete;

private:
    static std::deque<std::unique_ptr<Card>> getDeck(const std::string &fileName);
    static std::deque<std::unique_ptr<Card>> getDeckHelper(std::ifstream &deckFile);
    static std::deque<std::unique_ptr<Player>> getTeam(int teamSize);
    std::deque<std::unique_ptr<Card>> m_cards;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    int m_numOfRounds;
};



#endif /* MTMCHKIN_H_ */
