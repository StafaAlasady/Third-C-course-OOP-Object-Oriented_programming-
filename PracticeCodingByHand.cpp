#include <iostream>

int x;
int y;


int main (){

    x = 5;
    y = 6;

    if (x < y){
    std::cout << " display y: " << y <<std::endl;
    }else{
    std::cout << " display x: " << x <<std::endl;
    std::cout << " display y: " << y <<std::endl;
    }

    return 0;
}