#include "Card.h"
#include <sstream>

Card::Card(int r, Suit s) : rank(r), suit(s) {}

int Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }

std::string Card::toString() const {
    static const char* suitSymbols[] = {"C", "D", "H", "S"};
    static const char* rankSymbols[] = {"?", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::ostringstream os;
    os << rankSymbols[rank] << suitSymbols[static_cast<int>(suit)];
    return os.str();
}
