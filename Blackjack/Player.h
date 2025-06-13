#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <string>

/**
 * @class Player
 * @brief Represents a player in the Blackjack game.
 *
 * The Player class manages the player's name, hand of cards, balance, and betting actions.
 * It provides methods to interact with the player's hand, manage bets, and update the player's balance
 * based on the outcome of a game round.
 *
 * @note Each player starts with a default balance of 100.
 */
class Player
{
private:
    std::string name;
    Hand hand;
    int balance = 100;
    int currentBet = 0;

public:
    Player(const std::string &name);

    void takeCard(const Card &c);
    bool isBusted() const;
    int handValue() const;
    std::string handString() const;
    std::string getAsciiArt() const;
    std::string getSecondCardAscii() const;
    const std::string &getName() const;

    void setBet(int amount);
    int getBet() const;
    void win();
    void lose();
    void tie();
    int getBalance() const;

    const Hand &getHand() const;
};

#endif
