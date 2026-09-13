#include <iostream>
#include <vector>
#include <cmath>

    int correct  = 12;

    int questions = 15;

    double score = correct/(double)questions * 100;

    //std::cout << score << " %" << std::endl;



int main() {

    //std::string name;
    //int age;

    //std::cout <<" whats your full name ????: ";
    //std::getline(std::cin >> std::ws, name);
    
    //std::cout << "ah hell nahh, its this person again " << '\n';
    //std::cout << " anyways, hello there " << name << '\n';

    //std::cout << " how old are you ? " << name << '\n';
    //std::cin >> age;

    //std::cout << " you are " << age << " years old";

    double x = 3.94;
    double y = 4;
    double z;

    //z = std::max(x, y);
    //z = std::min(x, y);
    //z = pow(2, 4);
    //z = sqrt(16);
    //z = abs(-3);
    //z = round(x);
    //z = ceil(x);
    z = floor(x);


    std::cout << z;
    
    
    return 0;
}