#include <iostream>
#include <algorithm>
#include <cctype>

    double pricePerLiter = 16.6;
    double pricePerGallon = 6.1;

int main (){


    double gallons;
    double liters;
    std::string choice;

    std::cout << " Do you want to convert liters or gallons? " << std::endl;
    std::cin >> choice;

    std::transform(choice.begin(), choice.end(),choice.begin(), ::tolower);

    if(choice == "gallons"){
        std::cout << "youve picked gallons! \n";
        std::cout << "please input in gallons what you want to convert over to liters \n";
        std::cin >> gallons;
        std::cout << gallons * 3.785 << std::endl;
        std::cout << " Price for gasoline here would be:$ " << gallons * pricePerGallon << std::endl;
    }else if (choice == "liters")
    {
        std::cout << "youve picked liters! \n";
        std::cout << "please input in liters what you want to convert over to gallons \n";
        std::cin >> liters;
        std::cout << liters/3.785 << std::endl;

        std::cout << " Price for gasoline here would be:kr " << liters * pricePerLiter << std::endl;
    }else{
        std::cout << "sorry buddy, Invalid choice";
    }

    return 0;
}