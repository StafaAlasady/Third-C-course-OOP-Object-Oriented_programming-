#include <iostream>

int age;

int main(){

    std::cout << "Enter your age: ";
    std::cin >> age;

    if(age <= 0){
        std::cout << "you havent even been born yet, fraud \n";
    }
    else if(age > 99){
        std::cout << "wow youre still alive and kicking, welcome to the site \n";
    }
    else if(age >=18 ){
        std::cout << "Welcome to the site!" << std::endl;
    }
    else{
        std::cout << "youre not allowed in, youre too young, go do your homework kid \n";
    }

    return 0;
}