#include "Game.h"
#include <iostream>

/**
 * @brief Entry point of the Blackjack application.
 *
 * Displays a menu to the user with the following options:
 *   1. Start a new single game of Blackjack.
 *   2. Start a tournament mode with multiple rounds and ranking.
 *   3. View the score history.
 *   4. Quit the application.
 *
 * The function loops until the user chooses to quit.
 * User input is handled via standard input, and appropriate
 * methods of the Game class are called based on the user's choice.
 *
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    Game game;
    int choice;
    do
    {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. New single game\n";
        std::cout << "2. Tournament mode (rounds + ranking)\n";
        std::cout << "3. View score history\n";
        std::cout << "4. Quit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            game.playSingleGame();
            break;
        case 2:
            game.playTournament();
            break;
        case 3:
            game.displayScores();
            break;
        case 4:
            std::cout << "See you soon!\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}