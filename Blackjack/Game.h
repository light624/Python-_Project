#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"

class Game {
public:
    Game();
    void play();
private:
    Deck deck;
    Player player;
    Player dealer;
    void playerTurn();
    void dealerTurn();
    void showHands(bool showDealerHole) const;
};

#endif
