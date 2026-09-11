#include <iostream>





int main(){

    // int (number without decimal)
    int age = 21;
    int year = 2026;
    int days = 7.5;

    // double (number including decimal)
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 30.5;

    char grade = 'A';
    char initial = 'C';

    char currency = '$';

    std::cout << initial <<'\n';
    std::cout << currency;

    // boolean (there are only 2 states, either true or false)
    bool student = false;
    bool power = true;
    bool forsale = true;

    //string ( object where you can store more characters)
    std::string name = "Stafa ";
    std::string day = "Friday";
    std::string food = "Burgers";
    std::string adress = "My own empire";


    std::cout << "Hello " << name << '\n';
    std::cout << "where do you live ? " << adress << '\n';
    std::cout << "My favorite day of the week is " << day << '\n';


    return 0;
}