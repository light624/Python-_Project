#include "Deck.h"

/**
 * @brief Constructs a standard deck of 52 playing cards and shuffles it.
 *
 * Initializes the deck by creating 52 cards, one for each combination of rank (1 to 13)
 * and suit (0 to 3, cast to Suit enum). The deck is then shuffled using a random number generator.
 */
Deck::Deck() : rng(std::random_device{}())
{
    cards.reserve(52);
    for (int s = 0; s < 4; ++s)
    {
        for (int r = 1; r <= 13; ++r)
        {
            cards.emplace_back(r, static_cast<Suit>(s));
        }
    }
    shuffle();
}

/**
 * @brief Shuffles the deck of cards using a random number generator.
 *
 * Randomly rearranges the order of the cards in the deck to ensure fairness
 * in card distribution. Uses the internal random number generator `rng`.
 */
void Deck::shuffle()
{
    std::shuffle(cards.begin(), cards.end(), rng);
}

/**
 * @brief Deals a card from the deck.
 *
 * Removes and returns the card from the top of the deck (the back of the cards vector).
 *
 * @return Card The card dealt from the deck.
 */
Card Deck::deal()
{
    Card c = cards.back();
    cards.pop_back();
    return c;
}

/**
 * @brief Checks if the deck is empty.
 *
 * @return true if the deck contains no cards, false otherwise.
 */
bool Deck::empty() const
{
    return cards.empty();
}
