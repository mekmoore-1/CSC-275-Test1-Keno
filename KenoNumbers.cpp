#include <iostream>
#include <random>
#include "KenoNumbers.h"

//  constructor creates 20 positions of kenonumbers
KenoNumbers::KenoNumbers() {
    m_numbers = std::vector<int>(20);
}

// This will generate  random numbers from 1 to 80
void KenoNumbers::generateNumbers() {
    std::mt19937 gen;

    // Keep the required seed from the assignment
    gen.seed(0);

    std::uniform_int_distribution<int> distribution(1, 80);

    // Clear any numbers from the previous round
    clearKenoNumbers();

    // Generate each of the 20 numbers.
    for (int i = 0; i < 20; i++) {
        int number = 0;
        bool duplicate = true;

        // Generate another number if the number is already used
        for (; duplicate; ) {
            number = distribution(gen);
            duplicate = false;

            // Compares to see if it is duplicate
            for (int j = 0; j < i; j++) {
                if (m_numbers.at(j) == number) {
                    duplicate = true;
                }
            }
        }

        // Saves the number after it is not a duplicate
        m_numbers.at(i) = number;
    }
}

// This function returns the computer 20 numbers
std::vector<int> KenoNumbers::getKenoNumbers() const {
    return m_numbers;
}

// This function print keno numbers
void KenoNumbers::printKenoNumbers() const {
    std::cout << "Keno Numbers: ";

    for (int i = 0; i < 20; i++) {
        std::cout << m_numbers.at(i) << " ";
    }

    std::cout << "\n";
}

// This function clears the previous numbers
void KenoNumbers::clearKenoNumbers() {
    for (int i = 0; i < 20; i++) {
        m_numbers.at(i) = 0;
    }
}
