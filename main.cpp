#include "Player.h"
#include <iostream>
using namespace std;


int main() {
    Player* p1  = new Player("ori");
    Player* p2 = new Player("adi", 200);
    Player* p3 = new Player(*p2);

    if(&p3 == &p2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }



    return 0;
}

