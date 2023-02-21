#include "Merchant.h"

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getPlayerName(),player.getNumOfCoins());
    std::string input;
    int operation, cost = 0;
    bool validOperation;
    do {
        validOperation = true;
        try {
            std::getline(std::cin,input,'\n');
            operation = stoi(input, nullptr,10);
        } catch (std::exception& e) {
            printInvalidInput();
            validOperation = false;
            continue;
        }
        if(operation != BUY_NOTHING && operation != BUY_HEALTH_POTION && operation != BUY_FORCE_BOOST) {
            printInvalidInput();
            validOperation = false;
        }
    }
    while(!validOperation);

    if(operation == BUY_HEALTH_POTION){
        if(player.pay(HEALTH_POTION_COST)){
            player.heal(1);
            cost = HEALTH_POTION_COST;
        }else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(operation == BUY_FORCE_BOOST){
        if(player.pay(FORCE_BOOST_COST)){
            player.buff(1);
            cost = FORCE_BOOST_COST;
        } else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getPlayerName(),operation, cost);
}

std::string Merchant::getCardName() const {
    return "Merchant";
}