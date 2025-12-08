#include <stdio.h>

#include "cards.h"

int main() {
    CardDeck* deck = new_deck();
    shuffle(deck);
    while (has_more_cards(deck)) {
        Card* card = deal_card(deck);
        display_card(card);
    }
}

