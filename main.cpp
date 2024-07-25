#include <ios>
#include <iostream>
#include <limits>

#include "power_integer.hpp"

void clearStdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getUserInput() {
    bool done{false};
    int result{};

    while (!done) {
        std::cout << "Type an integer: ";
        std::cin >> result;

        if (std::cin.eof()) {
            std::cerr << "\nExiting the program ...\n";
            std::exit(EXIT_FAILURE);
        } else if (std::cin.fail()) {
            std::cerr << "Invalid input! Please type a valid integer.\n";
        } else if (std::cin.peek() != '\n') {
            std::cerr << "Invalid input! Please type valid digits only.\n";
        } else {
            done = true;
        }

        clearStdin();
    }

    return result;
}

int main() {
    std::cout << "Welcome to this simple exponent calculator!\n";

    const int base{getUserInput()};
    const int exponent{getUserInput()};

    auto result{pow_int(base, exponent)};

    if (result.has_value()) {
        std::cout << base << " to the power of " << exponent << " is: " << result.value() << ".\n";
    }

    return EXIT_SUCCESS;
}
