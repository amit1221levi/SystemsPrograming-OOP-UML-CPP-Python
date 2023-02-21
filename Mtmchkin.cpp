#include "Mtmchkin.h"



void Mtmchkin::copyCardsFrom(const Card* cardsArray, int numOfCards)
{
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i] = *(cardsArray + i);
    }
}

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player(playerName),
    m_gameStatus(GameStatus::MidGame),
    m_numOfCards(numOfCards),
    m_currentCardIndex(0)
{
    copyCardsFrom(cardsArray, numOfCards);  
}

Mtmchkin::Mtmchkin(Mtmchkin& game) :
    m_player(game.m_player),
    m_gameStatus(game.m_gameStatus),
    m_numOfCards(game.m_numOfCards),
    m_currentCardIndex(game.m_currentCardIndex)
{
    copyCardsFrom(game.m_cards, game.m_numOfCards);
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

void Mtmchkin::playNextCard()
{
    m_cards[m_currentCardIndex].printInfo();
    m_cards[m_currentCardIndex].applyEncounter(m_player);
    m_player.printInfo();
    if(m_player.getLevel() == Player::MAX_LEVEL) {
        m_gameStatus = GameStatus::Win;
    }
    if(m_player.isKnockedOut()) {
        m_gameStatus = GameStatus::Loss;
    }
    if(++m_currentCardIndex == m_numOfCards) {
        m_currentCardIndex = 0;
    }
}

bool Mtmchkin::isOver() const
{
    return (m_gameStatus == GameStatus::Loss || m_gameStatus == GameStatus::Win );
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}