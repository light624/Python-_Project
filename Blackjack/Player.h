#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"
#include <string>

class Player {
public:
    Player(const std::string& name);
    virtual ~Player() = default;
    void takeCard(const Card& c);
    bool isBusted() const;
    int handValue() const;
    std::string handString() const;
    const std::string& getName() const;
protected:
    std::string name;
    Hand hand;
};

#endif
