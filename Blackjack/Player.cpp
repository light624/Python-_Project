#include "Player.h"
#include <sstream>

Player::Player(const std::string &name) : name(name) {}

/**
 * @brief Adds a card to the player's hand.
 *
 * This function takes a constant reference to a Card object and adds it to the player's hand.
 *
 * @param c The card to be added to the player's hand.
 */
void Player::takeCard(const Card &c)
{
    hand.add(c);
}

/**
 * @brief Checks if the player's hand value exceeds 21 (busted).
 *
 * @return true if the total value of the player's hand is greater than 21, indicating the player is busted; false otherwise.
 */
bool Player::isBusted() const
{
    return hand.value() > 21;
}

/**
 * @brief Calculates and returns the total value of the player's hand.
 *
 * This function delegates the calculation to the associated Hand object,
 * returning the current value of the player's hand according to game rules.
 *
 * @return The integer value representing the total of the player's hand.
 */
int Player::handValue() const
{
    return hand.value();
}

/**
 * @brief Returns a string representation of the player's hand.
 *
 * This function calls the toString() method of the player's hand and returns
 * the resulting string, which describes the current cards held by the player.
 *
 * @return A string representing the player's hand.
 */
std::string Player::handString() const
{
    return hand.toString();
}

const std::string &Player::getName() const
{
    return name;
}

/**
 * @brief Retrieves the ASCII art representation of the player's hand.
 *
 * This function returns a string containing the ASCII art that visually
 * represents the current state of the player's hand.
 *
 * @return A std::string containing the ASCII art of the player's hand.
 */
std::string Player::getAsciiArt() const
{
    return hand.getAsciiArt();
}

/**
 * @brief Returns an ASCII representation of the player's second card, with the first card hidden.
 *
 * This function generates a string that visually represents two cards side by side.
 * The first card is displayed as hidden ("??"), while the second card shows its value and suit.
 * If the player has fewer than two cards, the function returns "[Hidden]".
 *
 * @return std::string ASCII art of the hidden first card and the visible second card, or "[Hidden]" if not enough cards.
 */
std::string Player::getSecondCardAscii() const
{
    const auto &cards = hand.getCards();
    if (cards.size() < 2)
        return "[Hidden]";
    std::string val = cards[1].getDisplayValue();
    std::string suit = cards[1].getSuitSymbol();
    std::ostringstream oss;
    oss << "┌────┐ ┌────┐\n";
    oss << "│ ?? │ │" << val << suit << "│\n";
    oss << "└────┘ └────┘";
    return oss.str();
}

void Player::setBet(int amount)
{
    currentBet = amount;
    balance -= amount;
}

int Player::getBet() const
{
    return currentBet;
}

/**
 * @brief Handles the player's winnings after a successful round.
 *
 * Doubles the player's current bet and adds it to their balance,
 * representing the payout for winning a round.
 */
void Player::win()
{
    balance += currentBet * 2;
}

/**
 * @brief Handles the outcome when the player ties in a game round.
 *
 * Restores the player's bet amount to their balance, as no money is won or lost in a tie.
 */
void Player::tie()
{
    balance += currentBet;
}

/**
 * @brief Handles the player's loss in the game.
 *
 * This method is called when the player loses a round.
 * Implement any logic needed to update the player's state,
 * such as adjusting balance, statistics, or displaying a message.
 */
void Player::lose()
{
}

int Player::getBalance() const
{
    return balance;
}

/**
 * @brief Returns a constant reference to the player's current hand.
 *
 * This function provides read-only access to the player's hand,
 * allowing external code to inspect the cards held by the player
 * without modifying them.
 *
 * @return const Hand& A constant reference to the player's hand.
 */
const Hand &Player::getHand() const
{
    return hand;
}
