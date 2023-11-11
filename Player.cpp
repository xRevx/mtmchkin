#include "Player.h"

Player::Player(char* name, int maxHP, int force){
    m_name = name;
    m_maxHP = maxHP;
    m_HP = m_maxHP;
    m_force = force;
    m_level = 1;
    m_coins = 0;
}

Player::Player(const Player& p1){
    *this = p1;
}

Player::~Player(){

}
Player& Player:: operator=(const Player& p){
    if(this == &p){
        return *this;
    }
    m_name = p.m_name;
    m_maxHP = p.m_maxHP;
    m_HP = p.m_HP;
    m_force = p.m_force;
    m_level = p.m_level;
    m_coins = p.m_coins;
    return *this;
}

