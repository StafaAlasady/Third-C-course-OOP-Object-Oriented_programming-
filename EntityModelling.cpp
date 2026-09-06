#include <iostream>
#include <string>

class Potion {
    private:
    std::string name;
    int healingPower;

public:
    Potion(std::string potionName, int power)
        :  name(potionName), healingPower(power) {}

    //getters to access the private attributes safely
    std::string getName() const {
        return name;
    }
    int getHealingPower() const {
        return healingPower;
    }

};

class Knight {
private:
    std::string name;
    int strength;
    int intelligence;
    int armor;
    int health;

public:
    // 1. Member Initializer List assigns parameters directly to private members
    Knight(std::string knightName, int knightStrength, int knightIntelligence, int knightArmor, int startingHealth = 100)
        : name(knightName), 
          strength(knightStrength), 
          intelligence(knightIntelligence), 
          armor(knightArmor),
          health(startingHealth)
    {
        // Spacing added before knightName: "Knight created: "
        std::cout << "Knight created: " << name << std::endl;
    }

    //Getters
    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }

    // 2. Method to display the Knight's stats
    void displayInfo() const {
        std::cout << "\n=== KNIGHT STATS ===" << std::endl;
        std::cout << "Name:         " << name << std::endl;
        std::cout << "Strength:     " << strength << std::endl;
        std::cout << "Intelligence: " << intelligence << std::endl;
        std::cout << "Armor:        " << armor << std::endl;
        std::cout << "Health:       " << health << std::endl;
        std::cout << "====================\n" << std::endl;
    }

    void usePotion(const Potion& potion) {
        std::cout << name << " Opens and drinks a " << potion.getName() << " !\n";
        health += potion.getHealingPower();
        std::cout << "-> " << name << "'s health restored by " << potion.getHealingPower()
            << ". Current Health: " << health << "\n";


    }
};

int main() {
    // Creating the object
    Knight arthur("King Arthur", 85, 60, 95, 40);

    Potion healthPotion("Greater Health Potion", 50);

    std::cout << "=== BEFORE INTERACTION ===\n";
    arthur.displayInfo();

    std::cout << "\n=== SIMULATING INTERACTION ===\n";
    // Knight interacts with the Item object
    arthur.usePotion(healthPotion);

    std::cout << "\n=== AFTER INTERACTION ===\n";
    arthur.displayInfo();
    return 0;
}