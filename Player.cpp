#pragma once

#include "Player.h"
#include "utilities.h"
#include <math.h>
#include <iostream>

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
 void Player::printInfo() const{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);

}
void Player::levelUp(){
    m_level < 10 ? m_level++ : m_level;
}
const int Player::getLevel(){
    return m_level;
}
void Player::buff(int force){
    m_force += force;
}
void Player::heal(int health){
    m_HP = std::min(m_maxHP ,m_HP + health);
}
void Player::damage(int damage){
    m_HP = std::max(0, m_HP - damage);
}
void Player::addCoins(int amount){
    m_coins += amount;
}



bool Player::pay(int amount){
    if(m_coins >= amount){
        m_coins -= amount;
        return true;
    }
    std::cout << "Not enough coins" << std::endl;
    return false;
}

bool const Player::isKnockedOut(){
    return m_HP == 0;
}

int const Player::getAttackStrength(){
    return m_level + m_force;
}


