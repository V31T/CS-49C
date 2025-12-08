#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define MAX_CARD 52

typedef enum {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,
} Suit;

typedef struct {
    short rank;
    Suit suit;
} Card;

typedef struct {
    Card cards[52];
    short next;
} CardDeck;


CardDeck* new_deck(void);

void shuffle(CardDeck*);

bool has_more_cards(CardDeck*);

Card* deal_card(CardDeck*);

char* get_suit(Card*);

void display_card(Card*);

#endif // Ending header guard

