#include <iostream>

class Character {
private:
    std::string name;
    int hitPoints;
    int attackStrength;
public:

    void displayInfo(const std::string& name, int hp, int attack) {
        std::cout << "Name: " << name << ", HP: " << hitPoints 
                  << ", Attack: " << attackStrength << std::endl;
    }
};


int main(){

    return 0;
}