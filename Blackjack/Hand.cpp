#include "Hand.h"
#include <sstream>

void Hand::add(const Card& card) {
    cards.push_back(card);
}

int Hand::value() const {
    int val = 0;
    int aces = 0;
    for (const auto& c : cards) {
        int r = c.getRank();
        if (r > 10) {
            val += 10;
        } else if (r == 1) {
            ++aces;
            val += 11;
        } else {
            val += r;
        }
    }
    while (val > 21 && aces > 0) {
        val -= 10;
        --aces;
    }
    return val;
}

std::string Hand::toString() const {
    std::ostringstream os;
    for (const auto& c : cards) {
        os << c.toString() << " ";
    }
    return os.str();
}
