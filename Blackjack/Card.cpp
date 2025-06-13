#include "Card.h"
#include <sstream>

Card::Card(int r, Suit s) : rank(r), suit(s) {}

int Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }

/**
 * @brief Converts the card to its string representation.
 *
 * The string representation consists of the card's rank followed by its suit symbol.
 * For example, "AS" for Ace of Spades, "10D" for Ten of Diamonds, etc.
 *
 * @return A std::string containing the rank and suit of the card.
 */
std::string Card::toString() const
{
    static const char *suitSymbols[] = {"C", "D", "H", "S"};
    static const char *rankSymbols[] = {"?", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::ostringstream os;
    os << rankSymbols[rank] << suitSymbols[static_cast<int>(suit)];
    return os.str();
}

/**
 * @brief Returns the display value of the card as a string.
 *
 * Converts the card's rank to its corresponding display value:
 * - "A" for Ace (rank 1)
 * - "J" for Jack (rank 11)
 * - "Q" for Queen (rank 12)
 * - "K" for King (rank 13)
 * - The numeric value as a string for ranks 2 through 10
 *
 * @return std::string The display value of the card.
 */
std::string Card::getDisplayValue() const
{
    if (rank == 1)
        return "A";
    if (rank == 11)
        return "J";
    if (rank == 12)
        return "Q";
    if (rank == 13)
        return "K";
    return std::to_string(rank);
}

/**
 * @brief Returns the Unicode symbol representing the card's suit, with color for red suits.
 *
 * This function returns a string containing the Unicode symbol for the card's suit.
 * For Hearts and Diamonds, the symbol is colored red using ANSI escape codes.
 * For Clubs and Spades, the symbol is displayed without color.
 *
 * @return std::string The suit symbol, optionally colored for red suits.
 */
std::string Card::getSuitSymbol() const
{
    std::string red = "\033[31m";
    std::string reset = "\033[0m";

    switch (suit)
    {
    case Suit::Hearts:
        return red + "♥" + reset;
    case Suit::Diamonds:
        return red + "♦" + reset;
    case Suit::Clubs:
        return "♣";
    case Suit::Spades:
        return "♠";
    default:
        return "?";
    }
}
