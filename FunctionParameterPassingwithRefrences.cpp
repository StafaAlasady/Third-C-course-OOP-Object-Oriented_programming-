#include <iostream>
#include <string>


struct Character{

    std::string name;
    int level;
    int experience;

};

    void levelUp(Character& charRef) {
    charRef.experience += 100;
    charRef.level++;
    std::cout << charRef.name << "You just leveled up! Level is now: " << charRef.level << std::endl;
}




int main(){

    Character Mustafa = {"Slayer", 10, 350};
    
    std::cout << "==== Before Level up ====" << std::endl;
    std::cout << "Name: " << Mustafa.name << std::endl;
    std::cout << "Level: " << Mustafa.level << std::endl;
    std::cout << "Experience: "<< Mustafa.experience << std::endl;

    levelUp(Mustafa);


    // Display stats AFTER level up
    std::cout << "\n=== After Level Up ===" << std::endl;
    std::cout << "Name: " << Mustafa.name << std::endl;
    std::cout << "Level: " << Mustafa.level << std::endl;
    std::cout << "Experience: " << Mustafa.experience << std::endl;

    return 0;
};