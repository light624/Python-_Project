#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>

class Deck {
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
