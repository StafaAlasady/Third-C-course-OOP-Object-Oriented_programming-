#include <iostream>
#include <cmath>



int main(){

    //double a;
    //double b;
    //double c;


    //std::cout << "Enter side A: ";
    //std::cin >> a;

    //std::cout << "Enter side B: ";
    //std::cin >> b;


    //a= pow (a, 2);
    //b= pow (b, 2);
    //c= sqrt( a + b );

    //std::cout << "side C: " << c;



    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age >= 18){
        std::cout << "welcome to the website" ;
    }
    else if(age < 0){
        std::cout << "youre not even born bro";
    }
    else{
        std::cout << "youre not old enough to enter this site. please leave";
    }



    return 0;
}