#include "Game.h"
#include <iostream>

Game::Game() : player("Player"), dealer("Dealer") {}

void Game::showHands(bool showDealerHole) const {
    std::cout << "Dealer: ";
    if (showDealerHole) {
        std::cout << dealer.handString() << "(" << dealer.handValue() << ")\n";
    } else {
        std::cout << "?? ";
        if (dealer.handString().size() > 0) {
            auto pos = dealer.handString().find(' ');
            if (pos != std::string::npos)
                std::cout << dealer.handString().substr(pos + 1);
        }
        std::cout << "\n";
    }
    std::cout << player.getName() << ": " << player.handString() << "(" << player.handValue() << ")\n";
}

void Game::playerTurn() {
    while (true) {
        showHands(false);
        if (player.isBusted()) {
            std::cout << "You bust!\n";
            return;
        }
        std::cout << "Hit or stand (h/s)? ";
        char choice;
        std::cin >> choice;
        if (choice == 'h' || choice == 'H') {
            player.takeCard(deck.deal());
        } else {
            break;
        }
    }
}

void Game::dealerTurn() {
    while (dealer.handValue() < 17) {
        dealer.takeCard(deck.deal());
    }
}

void Game::play() {
    deck.shuffle();
    player.takeCard(deck.deal());
    dealer.takeCard(deck.deal());
    player.takeCard(deck.deal());
    dealer.takeCard(deck.deal());

    playerTurn();
    if (!player.isBusted()) {
        dealerTurn();
    }

    showHands(true);
    if (player.isBusted()) {
        std::cout << "Dealer wins!\n";
    } else if (dealer.isBusted()) {
        std::cout << "You win! Dealer busts.\n";
    } else if (player.handValue() > dealer.handValue()) {
        std::cout << "You win!\n";
    } else if (player.handValue() < dealer.handValue()) {
        std::cout << "Dealer wins!\n";
    } else {
        std::cout << "Push!\n";
    }
}
