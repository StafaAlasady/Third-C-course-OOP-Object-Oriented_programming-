#include <iostream>

namespace SpeedMethod{
    int x = 1;
}

namespace SpeedMethod2{
    int x = 1;
}


int main(){
    const double pi = 3.14159;
    const double radius = 10;
    const double area = 2 * pi * radius;

    const double MyPunchingPower = 100000000;
    const double MySpeed = 100000000000000000;
    const double MyIq = 210;
    const double MyCock = 26;

    using namespace SpeedMethod;

    std::cout << area << " cm"<< '\n';
    return 0;
}