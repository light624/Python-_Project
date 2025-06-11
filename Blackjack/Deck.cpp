#include "Deck.h"

Deck::Deck() : rng(std::random_device{}()) {
    cards.reserve(52);
    for (int s = 0; s < 4; ++s) {
        for (int r = 1; r <= 13; ++r) {
            cards.emplace_back(r, static_cast<Suit>(s));
        }
    }
    shuffle();
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::deal() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::empty() const {
    return cards.empty();
}
