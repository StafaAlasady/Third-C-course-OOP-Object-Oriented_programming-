#include <iostream>


class BankAccount{
    private:
        int Balance;

    public:
    BankAccount(int initialBalance){
        if (initialBalance >= 0){
        Balance = initialBalance;
        } else {
            Balance = 0;
        }
    }
    int getBalance() const {
        return Balance;
    }

    bool setBalance(int newBalance) {
        if (newBalance >= 0) {
            Balance = newBalance;
            return true;
        }
        return false;
    }
};
class Character {
private:
    std::string name;
    int hitPoints;
    int attackStrength;
public:
    Character(std::string charName, int hp, int attack){
        name = charName;
        hitPoints = hp;
        attackStrength = attack;
    }
    void displayInfo() {
        std::cout << "Name: " << name
            << ", HP: " << hitPoints 
            << ", Attack: " << attackStrength << std::endl;
    }
    //Getters, the read only to the outside world.
    std::string getName() const {return name;}
    int getHitPoints() const {return hitPoints;}
    int getAttackStrength() const {return attackStrength;}

    //setters,the data back to the character and whats modifiable
    bool setHitPoints(int hp){
        if (hp >= 0 && hp <=100){
            hitPoints = hp;
            return true;
        } else {
            std::cout << "Error: Hp must be between 0 and 100. \n";
            return false;
        }
    }
    // Sets attackStrength with a validation check (cannot be negative)
    bool setAttackStrength(int attack) {
        if (attack >= 0) {
            attackStrength = attack;
            return true;
        }
        std::cout << "Error: Attack strength cannot be negative.\n";
        return false;
    }

    friend void applySuperBuff(Character& charObj, int Bonus);

};

    void applySuperBuff(Character& charObj, int Bonus) {
    std::cout << "\n[Admin Cheat] Applying super buff to " << charObj.name << "!\n";
    charObj.attackStrength += Bonus; // Directly modifying a private variable!
    };

int main(){
    Character hero("KNIGHT", 100, 25);
    //display the hero after creation and choosing their stats
    hero.displayInfo();

    // testing the setters
    std::cout << "Testing valid updates of the character \n";
    hero.setHitPoints(79);
    hero.setAttackStrength(25);
    hero.displayInfo();

    // 4. Test an invalid setter (bounds check!)
    std::cout << "\n--- Testing Invalid Update ---\n";
    hero.setHitPoints(150); // Should fail (above 100)
    hero.displayInfo();   // HP should still be 80 because it was rejected!

    // Call our friend function
    applySuperBuff(hero, 50);

    std::cout << "\n--- After Buff ---\n";
    hero.displayInfo();
    // 5. Test the applySuperBuff function


    return 0;
};