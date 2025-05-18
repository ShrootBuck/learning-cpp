#include <iostream>

int main() {

    std::string name;

    std::getline(std::cin >> std::ws, name);

    std::cout << "Hello " << name << "!";

    // Formatting for zsh
    std::cout << std::endl;
    return 0;
}
