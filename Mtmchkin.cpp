#include "Mtmchkin.h"

bool isValidPlayerName(const std::string& name){
    if (name.length() > 15 || name.empty()){
        return false;
    }
    for (char const &c : name) {
        if(!islower(c) && !isupper(c)){
            return false;
        }
    }
    return true;
}

bool isValidPlayerClass(const std::string& job){
    if(job == "Healer" || job == "Ninja" || job == "Warrior"){
        return true;
    }
    else{
        return false;
    }
}

std::deque<std::unique_ptr<Card>> Mtmchkin::getDeckHelper(std::ifstream &deckFile)
{
    int line = 0;
    std::deque<std::unique_ptr<Card>> cards;
    std::string cardType;
    while (getline(deckFile,cardType)){
        ++line;
        if(cardType == "Gremlin"){
            cards.push_back(std::unique_ptr<Gremlin>(new Gremlin()));
        } else if(cardType == "Witch") {
            cards.push_back(std::unique_ptr<Witch>(new Witch()));
        } else if(cardType == "Dragon"){
            cards.push_back(std::unique_ptr<Dragon>(new Dragon()));
        } else if(cardType == "Treasure"){
            cards.push_back(std::unique_ptr<Treasure>(new Treasure()));
        } else if(cardType == "Merchant"){
            cards.push_back(std::unique_ptr<Merchant>(new Merchant()));
        } else if(cardType == "Well"){
            cards.push_back(std::unique_ptr<Well>(new Well()));
        } else if(cardType == "Barfight"){
            cards.push_back(std::unique_ptr<Barfight>(new Barfight()));
        } else if(cardType == "Mana"){
            cards.push_back(std::unique_ptr<Mana>(new Mana()));
        } else{
            deckFile.close();
            throw DeckFileFormatError(line);
        }
    }
    if(cards.size() < MIN_SIZE_OF_DECK){
        deckFile.close();
        throw DeckFileInvalidSize();
    }
    deckFile.close();
    return cards;
}

std::deque<std::unique_ptr<Card>> Mtmchkin::getDeck(const std::string &fileName)
{
    std::ifstream deckFile(fileName, std::ios::in);
    if(deckFile.good()){
        //std::deque<std::unique_ptr<Card>> cards = getDeckHelper(deckFile);
        //return cards;
        return getDeckHelper(deckFile);
    }
    else {
        deckFile.close();
        throw DeckFileNotFound();
    }
}

int getTeamSize()
{
    std::string input;
    int teamSize;
    bool validTeamSize;
    printEnterTeamSizeMessage();
    do {
        validTeamSize = true;
        try {
            std::getline(std::cin,input,'\n');
            teamSize = stoi(input, nullptr,10);
        } catch (std::exception& e) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            validTeamSize = false;
            continue;
        }
        if(teamSize < 2 || teamSize > 6) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            validTeamSize = false;
        }
        
    }
    while(!validTeamSize);

    return teamSize;
}

std::deque<std::unique_ptr<Player>> Mtmchkin::getTeam(int teamSize)
{
    std::string input;
    std::deque<std::unique_ptr<Player>> players;
    for (int i = 0; i < teamSize; ++i) {
        printInsertPlayerMessage();
        std::string playerName ,playerClass;
        std::getline(std::cin,input,'\n');
        std::stringstream str(input);
        str>>playerName>>playerClass;
        while(!isValidPlayerName(playerName) || !isValidPlayerClass(playerClass)){
            if(!isValidPlayerName(playerName)){
                printInvalidName();
            }
            else if(!isValidPlayerClass(playerClass)){
                printInvalidClass();
            }
            std::getline(std::cin,input,'\n');
            std::stringstream str(input);
            str>>playerName>>playerClass;
        }
        if(playerClass == "Healer"){
            players.push_back(std::unique_ptr<Healer> (new Healer(playerName)));
        } else if(playerClass == "Ninja") {
            players.push_back(std::unique_ptr<Ninja>(new Ninja(playerName)));
        } else if(playerClass == "Warrior") {
            players.push_back(std::unique_ptr<Warrior>(new Warrior(playerName)));
        }

    }
    return players;
}

Mtmchkin::Mtmchkin(const std::string &fileName)
{
    printStartGameMessage();
    m_cards = getDeck(fileName);
    int teamSize = getTeamSize();
    m_players = getTeam(teamSize);
    m_numOfRounds = 0;
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(++m_numOfRounds);
    int numOfPlayers = m_players.size();
    for (int i = 0; i < numOfPlayers; ++i){
    printTurnStartMessage(m_players.front()->getPlayerName());
    (*m_cards.front()).applyEncounter(*m_players.front());
    if (m_players.front()->isWinner()) {
        m_winners.push_back(move(m_players.front()));
    } else if (m_players.front()->isKnockedOut()) {
        m_losers.push_front(move(m_players.front()));
    }
    else {
        m_players.push_back(move(m_players.front()));
    }
    m_players.pop_front();
    m_cards.push_back(move(m_cards.front()));
    m_cards.pop_front();
    }
    if(isGameOver()){
        printGameEndMessage();
    }

}

bool Mtmchkin::isGameOver() const
{
    if(m_players.empty()){
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numOfRounds;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank = 1;
    for(const std::unique_ptr<Player> & m_player: m_winners) {
        printPlayerLeaderBoard(rank,*m_player);
        rank++;
        }
    for(const std::unique_ptr<Player> & m_player : m_players) {
        printPlayerLeaderBoard(rank,*m_player);
        rank++;
    }
    for(const std::unique_ptr<Player> & m_player : m_losers) {
        printPlayerLeaderBoard(rank,*m_player);
        rank++;
    }
}
