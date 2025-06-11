#ifndef CARD_H
#define CARD_H
#include <string>

enum class Suit { Clubs, Diamonds, Hearts, Spades };

class Card {
public:
    Card(int r = 0, Suit s = Suit::Clubs);
    std::string toString() const;
    int getRank() const;
    Suit getSuit() const;
private:
    int rank; // 1-13 for Ace-King
    Suit suit;
};

#endif
