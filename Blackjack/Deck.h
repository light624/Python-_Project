#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>

/**
 * @class Deck
 * @brief Represents a standard deck of playing cards for use in games like Blackjack.
 *
 * The Deck class manages a collection of Card objects, providing functionality
 * to shuffle the deck, deal cards, and check if the deck is empty.
 *
 * @note The deck uses a Mersenne Twister random number generator for shuffling.
 */
class Deck
{
public:
    Deck();
    void shuffle();
    Card deal();
    bool empty() const;

private:
    std::vector<Card> cards;
    std::mt19937 rng;
};

#endif
