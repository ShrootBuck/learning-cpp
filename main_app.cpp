#include <iostream>

int main() {

    srand(time(0));
    int choice;

    std::cout << "1. Rock\n2. Paper\n3. Scissors\n";
    std::cin >> choice;

    std::string winner = "Tie!";

    int computerChoice = rand() % 3 + 1;

    switch (computerChoice) {
    case 1:
        std::cout << "Computer choses Rock";
        break;
    case 2:
        std::cout << "Computer choses Paper";
        break;
    case 3:
        std::cout << "Computer choses Scissors";
        break;
    }

    switch (choice) {
    case 1:
        switch (computerChoice) {
        case 2:
            winner = "computer";
            break;
        case 3:
            winner = "player";
            break;
        }
        break;

    case 2:
        switch (computerChoice) {
        case 1:
            winner = "player";
            break;
        case 3:
            winner = "computer";
            break;
        }
        break;

    case 3:
        switch (computerChoice) {
        case 1:
            winner = "computer";
            break;
        case 2:
            winner = "player";
            break;
        }
        break;
    }

    std::cout << winner;

    //////////
    std::cout << std::endl;
    return 0;
}
