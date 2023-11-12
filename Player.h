class Player{
    char* m_name;
    int m_level, m_force, m_maxHP, m_HP, m_coins;

public:
    Player(char* name, int maxHP = 100,int force = 5);
    Player(const Player& p1);
    ~Player();

    Player& operator=(const Player& p);

    void printInfo() const;

    //game functions
    void levelUp();
    const int getLevel();
    void buff(int force);
    void heal(int health);
    void damage(int damage); 
    void addCoins(int amount);
    bool pay(int amount);

    bool const isKnockedOut();
    int const getAttackStrength();
};