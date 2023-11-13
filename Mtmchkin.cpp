#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    m_player = new Player(playerName);
    m_cardsArray = cardsArray;
    m_numOfCards = numOfCards;
    m_status = GameStatus::MidGame;
    m_current_card = 0;
}

void Mtmchkin::playNextCard(){
    Card card =  m_cardsArray[m_current_card++ % m_numOfCards];
    card.printInfo();
    card.applyEncounter(*m_player);
}

bool Mtmchkin::isOver() const {
    return m_player->isKnockedOut();
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}