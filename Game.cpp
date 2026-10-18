#include <iostream>
#include <string>
#include "Game.h"

// Set up the game and start playing.
Game::Game()
{
    m_gameOver = false;
    playGame();
}

// Let the player play Keno and choose whether to play again.
void Game::playGame()
{
    std::string answer = "y";

    std::cout << "Welcome to Keno!\n";

    for (int i = 0; i < 10; i++)
    {
        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();

        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();

        displayResults();

        std::cout << "\nWould you like to play again? (y/n): ";
        std::cin >> answer;

        if (answer == "n")
        {
            break;
        }
        else if (answer == "N")
        {
            break;
        }
    }

    std::cout << "Thanks for playing Keno!\n";
}

// Display the player's picks, winning numbers, matches, and prize.
void Game::displayResults()
{
    std::cout << "\nKeno Numbers:\n";
    m_keno.printKenoNumbers();

    std::cout << "\nPlayer Picks:\n";
    m_player.printPlayerNumbers();

    printMatches();
}

// Find and display the matching numbers.
void Game::printMatches()
{
    int matchCount = 0;
    int prize = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (m_player.getPlayerNumbers().at(i) ==
                m_keno.getKenoNumbers().at(j))
            {
                m_matches.at(matchCount) =
                    m_player.getPlayerNumbers().at(i);
                matchCount++;
            }
        }
    }

    std::cout << "\nMatching numbers: ";

    for (int i = 0; i < matchCount; i++)
    {
        std::cout << m_matches.at(i) << " ";
    }

    if (matchCount == 10)
    {
        prize = 25000;
    }
    else if (matchCount == 9)
    {
        prize = 2500;
    }
    else if (matchCount == 8)
    {
        prize = 250;
    }
    else if (matchCount == 7)
    {
        prize = 50;
    }
    else if (matchCount == 6)
    {
        prize = 10;
    }
    else if (matchCount == 5)
    {
        prize = 5;
    }
    else
    {
        prize = 0;
    }

    std::cout << "\nMatching " << matchCount
              << " of 20 numbers wins $" << prize << "\n";
}

