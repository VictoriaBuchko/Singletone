#include <iostream>
using namespace std;

class Boss {
private:
    static Boss* s;
    int health;
    Boss(int i) {
        health = i;
    }
public:

    static Boss* getReference() {
        return s;
    }
    static void destroy() {

        if (s != nullptr) {
            cout << "Destroy" << endl;
            delete s;
            s = nullptr;
        }
    }
    
    int getHealth() {
        return health;
    }
    
    void setHealth(int i) {
        health = i;
        cout << "Boss health after hit: " << getHealth() << "\n\n";
        if (health <= 0) {
            cout << "Boss is defeated!" << endl;
            destroy();
        }
    }
};

Boss* Boss::s = new Boss(20);
int main() {
   
    Boss* p = Boss::getReference();
    
    cout << "Boss health: " << p->getHealth() << "\n\n";
    while (p->getHealth() > 0) {
        p->setHealth(p->getHealth() - 4);
    }

}



