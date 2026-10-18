#include <iostream>
#include <string>
#include "Player.h"

// constructor creating 10 spots for the player picks
Player::Player() {
    m_playerNumbers = std::vector<int>(10);
}

// this function get the 10 numbers from the player and makes sure that each input is a whole number between 1 and 80
void Player::inputPlayerNumbers() {
    std::string input;
    int number;
    bool validInput;
    bool duplicate;

    clearPlayerNumbers();

    std::cout << "Enter 10 unique numbers from 1 to 80.\n";

    // ask each time til 10 numbers have been entered
    for (int i = 0; i < 10; ) {
        validInput = true;
        number = 0;

        std::cout << "Enter pick " << i + 1 << ": ";
        std::getline(std::cin, input);

        // Checking whether the player entered anything valid or not
        if (input.length() == 0) {
            validInput = false;
        } else {
            // Checks each character to make sure it is a whole number
            for (int j = 0; j < input.length(); j++) {
                if (input.at(j) < '0' || input.at(j) > '9') {
                    validInput = false;
                } else if (validInput) {
                    // Convert the digits into a number.
                    number = number * 10 + (input.at(j) - '0');

                    if (number > 80) {
                        validInput = false;
                    }
                }
            }
        }

        // Makes sure the number is in the 1-80 range
        if (validInput) {
            if (number < 1 || number > 80) {
                validInput = false;
            }
        }

        // Checks if the player already entered this number
        if (validInput) {
            duplicate = false;

            for (int j = 0; j < i; j++) {
                if (m_playerNumbers.at(j) == number) {
                    duplicate = true;
                }
            }

            if (duplicate) {
                validInput = false;
                std::cout << "You already picked that number. Try again.\n";
            }
        }

        // Passes the valid input
        if (validInput) {
            m_playerNumbers.at(i) = number;
            i++;
        } else {
            std::cout << "Invalid entry. Enter a whole number from 1 to 80.\n";
        }
    }
}

// This function returns the player numbers
std::vector<int> Player::getPlayerNumbers() const {
    return m_playerNumbers;
}

// This function displays 10 numbers picked by the player
void Player::printPlayerNumbers() const {
    std::cout << "Player Picks: ";

    for (int i = 0; i < 10; i++) {
        std::cout << m_playerNumbers.at(i) << " ";
    }

    std::cout << "\n";
}

// This function clears the player numbers
void Player::clearPlayerNumbers() {
    for (int i = 0; i < 10; i++) {
        m_playerNumbers.at(i) = 0;
    }
}
