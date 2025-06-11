#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <vector>
#include <string>

class Hand {
public:
    void add(const Card& card);
    int value() const; // Blackjack value
    std::string toString() const;
private:
    std::vector<Card> cards;
};

#endif
