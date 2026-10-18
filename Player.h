#ifndef CSC_275_TEST_KENO_PLAYER_H
#define CSC_275_TEST_KENO_PLAYER_H

#include <vector>

class Player
{
private:
    // Stored 10 numbers that is selected by the player
    std::vector<int> m_playerNumbers = std::vector<int>(10);

public:
    // Created a Player object
    Player();

    // Getting 10 numbers from the player
    void inputPlayerNumbers();

    // Returns the player numbers
    std::vector<int> getPlayerNumbers() const;

    // Display the player numbers
    void printPlayerNumbers() const;

    // Clear player numbers
    void clearPlayerNumbers();
};

#endif




