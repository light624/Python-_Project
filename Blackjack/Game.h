#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include <vector>
#include <map>

/**
 * @class Game
 * @brief Manages the flow and logic of a Blackjack game, including players, dealer, and deck.
 *
 * The Game class encapsulates the core mechanics of a Blackjack game. It handles the initialization
 * of the deck, manages player and dealer turns, displays hands and results, and supports both single
 * games and tournament play. The class also provides functionality to display player scores.
 *
 * Private Members:
 * - Deck deck: The deck of cards used in the game.
 * - std::vector<Player> players: The list of players participating in the game.
 * - Player dealer: The dealer for the game.
 *
 * Private Methods:
 * - void playRound(): Conducts a single round of Blackjack for all players and the dealer.
 * - void playerTurn(Player& player): Manages the actions for a player's turn.
 * - void dealerTurn(): Manages the dealer's turn according to Blackjack rules.
 * - void showHands(const Player& player, bool showDealerHole) const: Displays the hands of the player and dealer.
 * - void showResult(const Player& player, std::map<std::string, double>* scores = nullptr): Shows the result for a player, optionally updating scores.
 *
 * Public Methods:
 * - Game(): Constructs a new Game instance, initializing players and deck.
 * - void playSingleGame(): Starts and manages a single game session.
 * - void playTournament(): Runs a tournament consisting of multiple game sessions.
 * - void displayScores() const: Displays the current scores of all players.
 */
class Game
{
private:
    Deck deck;
    std::vector<Player> players;
    Player dealer;

    void playRound();
    void playerTurn(Player &player);
    void dealerTurn();
    void showHands(const Player &player, bool showDealerHole) const;
    void showResult(const Player &player, std::map<std::string, double> *scores = nullptr);

public:
    Game();
    void playSingleGame();
    void playTournament();
    void displayScores() const;
};

#endif
