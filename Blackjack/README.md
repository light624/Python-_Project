# Blackjack Console Game

This is a simple command-line Blackjack game implemented in C++. The program
uses classes, functions and the C++ Standard Library. It allows one human
player to play against a dealer following standard Blackjack rules (no advanced
options like splitting or doubling down).

## Building

A C++17 compiler is required. You can compile everything using `make`:

```bash
make
```

Alternatively, compile manually:

```bash
g++ -std=c++17 -o blackjack main.cpp Card.cpp Deck.cpp Hand.cpp Player.cpp Game.cpp
```

## Running

After building, run the executable:

```bash
./blackjack
```

Follow the prompts to hit or stand until the round ends. The program will
announce the winner and exit.
