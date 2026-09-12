#include <iostream>

    int correct  = 12;

    int questions = 15;

    double score = correct/(double)questions * 100;

    //std::cout << score << " %" << std::endl;



int main() {

    std::string name;
    int age;

    std::cout <<" whats your full name ????: ";
    std::getline(std::cin >> std::ws, name);
    
    std::cout << "ah hell nahh, its this person again " << '\n';
    std::cout << " anyways, hello there " << name << '\n';

    std::cout << " how old are you ? " << name << '\n';
    std::cin >> age;

    std::cout << " you are " << age << " years old";
    
    
    return 0;
}