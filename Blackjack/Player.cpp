#include "Player.h"

Player::Player(const std::string& name) : name(name) {}

void Player::takeCard(const Card& c) {
    hand.add(c);
}

bool Player::isBusted() const {
    return hand.value() > 21;
}

int Player::handValue() const {
    return hand.value();
}

std::string Player::handString() const {
    return hand.toString();
}

const std::string& Player::getName() const {
    return name;
}
