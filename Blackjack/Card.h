#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

/**
 * @class Card
 * @brief Represents a playing card with a rank and suit.
 *
 * The Card class encapsulates the properties and behaviors of a standard playing card,
 * including its rank (Ace through King) and suit (Clubs, Diamonds, Hearts, Spades).
 */
class Card
{
public:
    Card(int r = 0, Suit s = Suit::Clubs);

    int getRank() const;
    Suit getSuit() const;
    std::string toString() const;

    std::string getDisplayValue() const;
    std::string getSuitSymbol() const;

private:
    int rank; // 1–13: A=1, J=11, Q=12, K=13
    Suit suit;
};

#endif
