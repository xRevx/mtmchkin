class Player{
    char* m_name;
    int m_level, m_force, m_maxHP, m_HP, m_coins;

public:
    Player(char* name, int maxHP = 100,int force = 5);
    Player(const Player& p1);
    ~Player();

    Player& operator=(const Player& p);
};