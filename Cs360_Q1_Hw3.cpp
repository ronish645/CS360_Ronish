#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Card {
public:
    static std::vector<std::string> faces;
    static std::vector<std::string> suits;

    Card(int face, int suit) : face(face), suit(suit) {}

    std::string toString() {
        return faces[face] + " of " + suits[suit];
    }

private:
    int face;
    int suit;
};

std::vector<std::string> Card::faces = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
std::vector<std::string> Card::suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards {
public:
    DeckOfCards() {
        for(int face = 0; face < 13; ++face) {
            for(int suit = 0; suit < 4; ++suit) {
                deck.push_back(Card(face, suit));
            }
        }
    }

    void shuffle() {
        std::srand(std::time(0));
        std::random_shuffle(deck.begin(), deck.end());
        currentCard = 0;
    }

    Card dealCard() {
        return deck[currentCard++];
    }

    bool moreCards() {
        return currentCard < deck.size();
    }

private:
    std::vector<Card> deck;
    int currentCard = 0;
};

int main() {
    DeckOfCards deck;
    deck.shuffle();
    while(deck.moreCards()) {
        std::cout << deck.dealCard().toString() << std::endl;
    }
    return 0;
}
