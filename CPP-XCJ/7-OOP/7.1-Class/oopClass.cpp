#include <iostream>
#include <string>
using namespace std;

/*
Requirement:
(1) 2 npc (name, hp)
(2) attack
*/
class NPC
{
public:
    string name_;
    int health_{100};

    inline void Attack(int atk) {
        health_ -= atk;
        cout << name_ << " was attacked!" << " - " << atk <<endl;
    }

    inline void TestThis() {
        cout << "This address = " << (long long) this << endl;
    }
};


int main()
{
    NPC npc1;
    NPC npc2;

    npc1.name_ = "npc1";
    npc2.name_ = "npc2";

    npc1.Attack(50);
    npc2.Attack(60);

    NPC* npc3 = new NPC;
    npc3->name_ = "npc3";
    npc3->Attack(70);

    (&npc1)->Attack(10);
    (*npc3).Attack(30);

    delete npc3;

    npc1.TestThis();
    cout << "npc1 address = " << (long long) &npc1 << endl;
}
