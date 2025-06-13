#include "Hand.h"
#include <sstream>

/**
 * @brief Adds a card to the hand.
 *
 * Appends the specified card to the collection of cards held in the hand.
 *
 * @param card The card to be added to the hand.
 */
void Hand::add(const Card &card)
{
    cards.push_back(card);
}

/**
 * @brief Calculates the total value of the hand according to Blackjack rules.
 *
 * This function iterates through all cards in the hand, summing their values.
 * Face cards (Jack, Queen, King) are counted as 10. Aces are initially counted as 11,
 * but if the total value exceeds 21, each Ace can be counted as 1 instead (by subtracting 10)
 * until the total value is 21 or less, or there are no more Aces to adjust.
 *
 * @return The total Blackjack value of the hand.
 */
int Hand::value() const
{
    int val = 0;
    int aces = 0;
    for (const auto &c : cards)
    {
        int r = c.getRank();
        if (r > 10)
            val += 10;
        else if (r == 1)
        {
            ++aces;
            val += 11;
        }
        else
        {
            val += r;
        }
    }
    while (val > 21 && aces > 0)
    {
        val -= 10;
        --aces;
    }
    return val;
}

/**
 * @brief Returns a string representation of the hand.
 *
 * Iterates through all cards in the hand and concatenates their string representations,
 * separated by spaces, into a single string.
 *
 * @return A string containing the string representations of all cards in the hand, separated by spaces.
 */
std::string Hand::toString() const
{
    std::ostringstream os;
    for (const auto &c : cards)
    {
        os << c.toString() << " ";
    }
    return os.str();
}

/**
 * @brief Generates an ASCII art representation of the hand's cards.
 *
 * Iterates through all cards in the hand and constructs a multi-line string
 * where each card is displayed side by side using ASCII art. Each card is
 * represented by its value and suit symbol, properly aligned for single-digit
 * values. The resulting string contains three lines: the top border, the
 * middle with value and suit, and the bottom border.
 *
 * @return A std::string containing the ASCII art representation of the hand.
 */
std::string Hand::getAsciiArt() const
{
    std::stringstream top, mid, bot;

    for (const Card &card : cards)
    {
        std::string value = card.getDisplayValue();
        std::string suit = card.getSuitSymbol();

        if (value.size() == 1)
            value += " "; // Alignement

        top << "┌────┐ ";
        mid << "│" << value << suit << "│ ";
        bot << "└────┘ ";
    }

    return top.str() + "\n" + mid.str() + "\n" + bot.str() + "\n";
}

const std::vector<Card> &Hand::getCards() const
{
    return cards;
}
