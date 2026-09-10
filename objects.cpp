#include <iostream>
#include <string>

// 1. Defining Character class
class Character {
private:
    std::string name;
    int health;

public:
    Character(std::string charName, int charHealth) 
        : name(charName), health(charHealth) {}
    void displayStatus() const {
        std::cout << "Character Name: " << name << " | Health: " << health << std::endl;
    }
};

int main() {
    // 2. Creating an object and calling the member function
    Character hero("Arthur", 100);
    hero.displayStatus();

    return 0;
}