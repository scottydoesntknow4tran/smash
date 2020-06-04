#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

using namespace std;

class Warrior{
    protected:
    int BaseAttack;
    int BaseBlock;

    public:
    string name;
    int health;
    Warrior(string name, int health, int BaseAttack, int BaseBlock){
        this->name= name;
        this->health = health;
        this->BaseAttack =BaseAttack;
        this->BaseBlock = BaseBlock;
    }

    int Attack(){
        return (rand()%10)+BaseAttack;

    }
    int Block(){
        return (rand()%10)+BaseBlock;

    }
};


class Battle{
public:
    static void StartFight(Warrior& Warrior1, Warrior& Warrior2){
        while(true){
            if(Battle::GetAttackResult(Warrior1,Warrior2).compare("Game Over")==0){
                cout<< "Game Over\n";
                break;
            }
            if(Battle::GetAttackResult(Warrior2,Warrior1).compare("Game Over")==0){
                cout<< "Game Over\n";
            break;
            }

        
        }

    }
    static string GetAttackResult(Warrior& WarriorA, Warrior& WarriorB){
        int WAATCK= WarriorA.Attack();
        int WBBLK= WarriorB.Block();
        int dmg2WB = WAATCK -WBBLK;
        dmg2WB = (dmg2WB<=0)? 0: dmg2WB;
        WarriorB.health = WarriorB.health -dmg2WB;

        cout << WarriorA.name<< " attacks "<< WarriorB.name
         << " and deals " << dmg2WB << " damage!\n";

        cout << WarriorB.name<< " has " << WarriorB.health
        << " health left\n";

         if(WarriorB.health <= 0){
             cout << WarriorB.name << " has died "<< WarriorA.name
             << " is Victorious\n";
         
        return "Game Over";
         }
        return "Battle Continues";
    }
};

int main()
{
srand(time(NULL));
Warrior type1 ("Thor",119,12,13);
Warrior type2 ("Hulk",204,10,17);

Battle::StartFight(type1,type2);

return 0;
}
