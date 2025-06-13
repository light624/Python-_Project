#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>
#include <string>

/**
 * @class Hand
 * @brief Represents a hand of cards in a Blackjack game.
 *
 * The Hand class manages a collection of Card objects, providing
 * functionality to add cards, calculate the hand's value, and
 * generate string or ASCII art representations of the hand.
 */
class Hand
{
public:
    void add(const Card &card);
    int value() const;
    std::string toString() const;
    std::string getAsciiArt() const;
    const std::vector<Card> &getCards() const;

private:
    std::vector<Card> cards;
};

#endif
