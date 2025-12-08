#include "cards.h"

#define NUM_SHUFFLES 2048

/**
 * Returns the suit of a card.
 */
char* get_suit(Card* card) {
    switch(card->suit) {
        case SPADES:
            return "Spades";
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
    }
}

/**
 * Prints out the suit and rank of a card.
 */
void display_card(Card* card) {
    assert(card->rank > 0 && card->rank < MAX_CARD);

    char* suit_str = get_suit(card);

    switch (card->rank) {
        case 1:
            printf("Ace of %s.\n", suit_str);
            break;
        case 11:
            printf("Jack of %s.\n", suit_str);
            break;
        case 12:
            printf("Queen of %s.\n", suit_str);
            break;
        case 13:
            printf("King of %s.\n", suit_str);
            break;
        default:
            printf("%d of %s.\n", card->rank, suit_str);
    }
}

/**
 * Creates the deck of cards, but does not shuffle it.
 */
void init_deck(CardDeck* deck) {
    for (int i=0; i<MAX_CARD; i++) {
        deck->cards[i].rank = (i%13) + 1; // ranks will be 1-13
        deck->cards[i].suit = (i/13); // suits will be 0-3
    }
}

/**
 * Creates a new deck of cards.
 */
CardDeck* new_deck() {
    CardDeck* deck = (CardDeck*) malloc(sizeof(CardDeck));
    deck->next = 0;
    init_deck(deck);
    return deck;
}

/**
 * Returns true if there are more cards in the deck.
 */
bool has_more_cards(CardDeck* deck) {
    return deck->next < MAX_CARD;
}

/**
 * Returns the next card.
 */
Card* deal_card(CardDeck* deck) {
    assert (deck->next < MAX_CARD);
    return &deck->cards[deck->next++];
}

/**
 * Prints out the deck of cards for debugging purposes.
 */
void show_deck(CardDeck* deck) {
    for (int i=0; i<MAX_CARD; i++) {
        Card cd = deck->cards[i];
        display_card(&cd);
    }
}

