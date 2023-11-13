
#include "Card.h"

Card::Card(CardType type, const CardStats& stats){
    m_effect = type;
    m_stats = stats;
}
void Card::applyEncounter(Player& player) const{
    bool win = false;
    switch(m_effect){

        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;

        case CardType::Battle:
            if(player.getAttackStrength() >= m_stats.force){
                player.addCoins(m_stats.loot);
                win = true;
            }
            else{
                player.damage(m_stats.force);
            }
            printBattleResult(win);
            break;
        
        case CardType::Buff:
            player.pay(m_stats.cost);
            player.buff(m_stats.buff);
            break;

        case CardType::Heal:
            player.pay(m_stats.cost);
            player.heal(m_stats.heal);
            break;
        default:
            break;
    }
}
void Card::printInfo() const{
    switch(m_effect){
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;

        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;

        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
    }
}


