#include "Game.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <algorithm>

Game::Game() : dealer("Dealer") {}

/**
 * @brief Starts and manages a single game of Blackjack.
 *
 * This function clears the current list of players, prompts the user to enter the number of players,
 * and collects each player's name. It then initiates a round of Blackjack and displays the result
 * for each player at the end of the round.
 *
 * Steps performed:
 * 1. Clears the existing players.
 * 2. Prompts for and reads the number of players.
 * 3. Collects each player's name and adds them to the game.
 * 4. Plays a round of Blackjack.
 * 5. Shows the result for each player.
 */
void Game::playSingleGame()
{
    players.clear();
    int numPlayers;
    std::cout << "How many players? ";
    std::cin >> numPlayers;
    std::cin.ignore();

    for (int i = 0; i < numPlayers; ++i)
    {
        std::string name;
        std::cout << "Player name " << (i + 1) << ": ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    playRound();

    for (auto &player : players)
    {
        showResult(player);
    }
}

/**
 * @brief Runs a full Blackjack tournament with multiple players and rounds.
 *
 * This function manages the entire flow of a Blackjack tournament, including:
 * - Prompting the user for the number of players and their names.
 * - Asking for the number of rounds (manches) to play.
 * - Playing each round, updating player balances, and eliminating players with zero tokens.
 * - Displaying results after each round and removing eliminated players.
 * - Sorting and displaying the final ranking of players by their balances.
 * - Announcing the winner with celebratory ASCII art and a congratulatory message.
 * - Displaying a random motivational or game-related quote at the end of the tournament.
 *
 * The tournament ends early if all players are eliminated before all rounds are completed.
 */
void Game::playTournament()
{
    players.clear();
    // Clear previous scores at the start of the game
    std::ofstream clearFile("scores.txt", std::ios::trunc);

    int numPlayers, nbManches;
    std::cout << "How many players? ";
    std::cin >> numPlayers;
    std::cin.ignore();

    for (int i = 0; i < numPlayers; ++i)
    {
        std::string name;
        std::cout << "Player name " << (i + 1) << ": ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    std::cout << "Number of rounds : ";
    std::cin >> nbManches;

    std::map<std::string, double> scores;

    for (int manche = 1; manche <= nbManches; ++manche)
    {
        std::cout << "\n===== Manche " << manche << " =====\n";
        playRound();

        for (auto &player : players)
        {
            showResult(player, &scores);
        }
        // Suppress players with zero balance
        players.erase(
            std::remove_if(players.begin(), players.end(),
                           [](const Player &p)
                           {
                               if (p.getBalance() <= 0)
                               {
                                   std::cout << p.getName() << " was eliminated (out of tokens).\n";
                                   return true;
                               }
                               return false;
                           }),
            players.end());

        // End of game if no players left
        if (players.empty())
        {
            std::cout << "No players left. Tournament ends.\n";
            return;
        }

        std::cout << "-------------------------------\n";
    }

    // Display ranking
    // Sort players by balance descending
    std::sort(players.begin(), players.end(),
              [](const Player &a, const Player &b)
              {
                  return a.getBalance() > b.getBalance();
              });

    std::cout << "\n💰 FINAL RANKING BY BALANCE 💰\n";
    if (!players.empty())
    {
        const auto &winner = players.front();
        std::cout << "\n\n🎉🏆 CONGRATULATIONS, " << winner.getName() << "! 🏆🎉\n";
        std::cout << R"(

  ██████╗ ██╗   ██╗ █████╗ ███╗   ██╗██╗ ██████╗ ███████╗
 ██╔═══██╗██║   ██║██╔══██╗████╗  ██║██║██╔════╝ ██╔════╝
 ██║   ██║██║   ██║███████║██╔██╗ ██║██║██║  ███╗█████╗  
 ██║▄▄ ██║██║   ██║██╔══██║██║╚██╗██║██║██║   ██║██╔══╝  
 ╚██████╔╝╚██████╔╝██║  ██║██║ ╚████║██║╚██████╔╝███████╗
  ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝ ╚══════╝

)";
        std::cout << "\n👑 " << winner.getName() << " has proven to be the true Blackjack Champion!";
        std::cout << "\n💸 Final balance: " << winner.getBalance() << " tokens";
        std::cout << "\n🥇 A master of strategy, risk and luck. Well played!\n\n";
        std::cout << "\a"; // Terminal beep (bell character)
    }

    for (const auto &player : players)
    {
        std::cout << std::setw(10) << player.getName()
                  << " : " << player.getBalance() << " tokens\n";
    }

    std::cout << R"(
  _______ _                 _   _                 _ 
 |__   __| |               | | (_)               | |
    | |  | |__   __ _ _ __ | |_ _  ___  _ __  ___| |
    | |  | '_ \ / _` | '_ \| __| |/ _ \| '_ \/ __| |
    | |  | | | | (_| | | | | |_| | (_) | | | \__ \_|
    |_|  |_| |_|\__,_|_| |_|\__|_|\___/|_| |_|___(_)
                                                    
     ████████╗██╗  ██╗ █████╗ ███╗   ██╗██╗  ██╗    
     ╚══██╔══╝██║  ██║██╔══██╗████╗  ██║╚██╗██╔╝    
        ██║   ███████║███████║██╔██╗ ██║ ╚███╔╝     
        ██║   ██╔══██║██╔══██║██║╚██╗██║ ██╔██╗     
        ██║   ██║  ██║██║  ██║██║ ╚████║██╔╝ ██╗    
        ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝    

      Thank you for being part of this Blackjack tournament!
      We hope you had fun and enjoyed the challenge 🎲🃏
)" << "\n";
    /**
     * @brief A collection of motivational and game-related quotes.
     *
     * This vector contains a set of inspirational quotes from various authors and sources,
     * including famous personalities and a Blackjack proverb. These quotes can be used to
     * motivate players or display messages during the game.
     */
    std::vector<std::string> quotes = {
        "\"The harder the battle, the sweeter the victory.\" – Les Brown",
        "\"In the middle of difficulty lies opportunity.\" – Albert Einstein",
        "\"Victory is in having done your best. If you’ve done your best, you’ve won.\" – Billy Bowerman",
        "\"Sometimes you win, sometimes you learn.\" – John C. Maxwell",
        "\"Luck is what happens when preparation meets opportunity.\" – Seneca",
        "\"Don’t count the chips. Make the chips count.\" – Blackjack proverb",
        "\"It’s not about beating others. It’s about beating your own limits.\" – Anonymous"};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int index = std::rand() % quotes.size();
    std::cout << "\n📣 " << quotes[index] << "\n";
}

/**
 * @brief Plays a single round of Blackjack for all players and the dealer.
 *
 * This function resets the dealer and deck, shuffles the deck, and initializes each player
 * for the round. Each player is prompted to place a bet within their balance, and is dealt two cards.
 * The dealer is also dealt two cards. Then, each player takes their turn, followed by the dealer's turn.
 *
 * The function manages the flow of a complete round, including betting, dealing, and player/dealer actions.
 */
void Game::playRound()
{
    dealer = Player("Dealer");
    deck = Deck();
    deck.shuffle();

    for (auto &player : players)
    {
        player = Player(player.getName());

        std::cout << player.getName() << ", current balance : " << player.getBalance() << " tokens.\n";
        int mise = 0;
        do
        {
            std::cout << "Enter your bet : ";
            std::cin >> mise;
        } while (mise < 1 || mise > player.getBalance());

        player.setBet(mise);
        player.takeCard(deck.deal());
        player.takeCard(deck.deal());
    }

    dealer.takeCard(deck.deal());
    dealer.takeCard(deck.deal());

    for (auto &player : players)
    {
        playerTurn(player);
    }

    dealerTurn();
}

/**
 * @brief Handles the player's turn in the Blackjack game.
 *
 * This function manages the logic for a single player's turn. It repeatedly displays the player's
 * and dealer's hands, checks if the player has busted (i.e., their hand value exceeds 21),
 * and prompts the player to either "hit" (take another card) or "stand" (end their turn).
 * If the player chooses to hit, a card is dealt to them. The loop continues until the player
 * either stands or busts.
 *
 * @param player Reference to the Player object whose turn is being processed.
 */
void Game::playerTurn(Player &player)
{
    while (true)
    {
        showHands(player, false);
        if (player.isBusted())
        {
            std::cout << player.getName() << " busted (over 21) !\n";
            return;
        }
        std::cout << "Hit ou stand (h/s) ? ";
        char choice;
        std::cin >> choice;
        if (choice == 'h')
        {
            player.takeCard(deck.deal());
        }
        else
        {
            break;
        }
    }
}

/**
 * @brief Executes the dealer's turn in the Blackjack game.
 *
 * The dealer will continue to draw cards from the deck and add them to their hand
 * until the total value of the dealer's hand is at least 17, following standard Blackjack rules.
 */
void Game::dealerTurn()
{
    while (dealer.handValue() < 17)
    {
        dealer.takeCard(deck.deal());
    }
}

/**
 * @brief Displays the current hands of the dealer and the player in the Blackjack game.
 *
 * This function prints the ASCII art representation and hand values for both the dealer and the player.
 * If @p showDealerHole is true, the dealer's full hand is shown; otherwise, only the dealer's second card is displayed (hiding the hole card).
 *
 * @param player The player whose hand will be displayed.
 * @param showDealerHole If true, reveals the dealer's full hand; if false, hides the dealer's hole card.
 */
void Game::showHands(const Player &player, bool showDealerHole) const
{
    std::cout << "\n═════════════════════════════════\n";
    std::cout << "            BLACKJACK\n";
    std::cout << "═════════════════════════════════\n";

    std::cout << "Dealer:\n";
    if (showDealerHole)
    {
        std::cout << dealer.getAsciiArt();
        std::cout << "Total: " << dealer.handValue() << "\n";
    }
    else
    {
        std::cout << dealer.getSecondCardAscii() << "\n";
    }

    std::cout << "\n"
              << player.getName() << ":\n";
    std::cout << player.getAsciiArt();
    std::cout << "Total: " << player.handValue() << "\n\n";
}

/**
 * @brief Displays the result of a Blackjack round for a given player, updates scores and logs the outcome.
 *
 * This function shows both the player's and dealer's hands, determines the outcome of the round
 * (Victory, Defeat, or Tie), updates the player's status and balance accordingly, and optionally
 * updates a provided scores map. The result is appended to a "scores.txt" log file with a timestamp,
 * and a summary is printed to the console.
 *
 * @param player The player whose result is being shown. The player's status and balance may be modified.
 * @param scores Optional pointer to a map storing cumulative scores for each player by name. If provided,
 *               the player's score is incremented based on the round's outcome (1.0 for win, 0.5 for tie, 0.0 for loss).
 */
void Game::showResult(const Player &player, std::map<std::string, double> *scores)
{
    showHands(player, true);
    int playerScore = player.handValue();
    int dealerScore = dealer.handValue();

    std::string result;
    double score = 0.0;

    if (playerScore > 21)
    {
        result = "Defeat";
        const_cast<Player &>(player).lose();
    }
    else if (dealerScore > 21 || playerScore > dealerScore)
    {
        result = "Victory";
        const_cast<Player &>(player).win();
        score = 1.0;
    }
    else if (playerScore < dealerScore)
    {
        result = "Defeat";
        const_cast<Player &>(player).lose();
    }
    else
    {
        result = "Tie";
        const_cast<Player &>(player).tie();
        score = 0.5;
    }

    if (scores)
    {
        (*scores)[player.getName()] += score;
    }

    std::ofstream file("scores.txt", std::ios::app);
    std::time_t now = std::time(nullptr);
    file << "[" << std::ctime(&now) << "] "
         << player.getName() << ": " << playerScore
         << " | Dealer: " << dealerScore
         << " → " << result
         << " | Solde: " << player.getBalance() << " tokens\n";

    std::cout << "Result for " << player.getName() << " : " << result
              << " | Current balance : " << player.getBalance() << " tokens\n";
}

/**
 * @brief Displays the score history from the "scores.txt" file.
 *
 * This function attempts to open the "scores.txt" file and prints its contents
 * to the standard output. If the file does not exist or cannot be opened,
 * it notifies the user that no score is recorded. The output is formatted
 * with a header and footer for clarity.
 *
 * @note This function does not modify any class members and is marked as const.
 */
void Game::displayScores() const
{
    std::ifstream file("scores.txt");
    if (!file)
    {
        std::cout << "No score recorded.\n";
        return;
    }

    std::cout << "\n===== SCORE HISTORY =====\n";
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << "\n";
    }
    std::cout << "=================================\n";
}