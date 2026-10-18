#ifndef CSC_275_TEST1_KENO_GAME_H
#define CSC_275_TEST1_KENO_GAME_H

#include "Player.h"
#include "KenoNumbers.h"
#include <vector>

class Game
{
private:
    KenoNumbers m_keno;
    Player m_player;
    std::vector<int> m_matches = std::vector<int>(10);
    bool m_gameOver;

public:
    Game();

private:
    void playGame();
    void displayResults();
    void printMatches();
};

#endif
