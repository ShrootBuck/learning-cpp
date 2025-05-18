#include <iostream>

int main() {
    double temp;
    char   unit;

    std::cout << "What unit would you like to convert to? (F/C)";

    std::cin >> unit;

    if (unit == 'F' || unit == 'f') {
        std::cout << "Enter the temperature in Celsius: ";
        std::cin >> temp;
        temp = (1.8 * temp) + 32;
        std::cout << "Temperature is " << temp << " degrees F\n";
    } else if (unit == 'C' || unit == 'c') {
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temp;

        temp = (temp - 32) / 1.8;
        std::cout << "Temperature is: " << temp << "C\n";
    } else {
        std::cout << "Please enter only C or F!";
    }

    // Stupid Zsh stuff
    std::cout << std::endl;
}
