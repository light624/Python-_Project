CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra
OBJS=main.o Card.o Deck.o Hand.o Player.o Game.o

blackjack: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) blackjack
