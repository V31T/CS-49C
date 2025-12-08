#include <stdio.h>

#include "cards.h"

void clear_screen() {
    printf("\033[2J\033[H");
}

/**
 * Shuffles cards only if needed -- otherwise deals.
 */
Card* deal(CardDeck* deck) {
    if (!has_more_cards(deck)) {
        shuffle(deck);
    }
    return deal_card(deck);
}

/**
 * Returns the amount won (or lost) by the player.
 */
int play_game(CardDeck* deck, int player_balance, int computer_balance) {
    Card* player_card = deal(deck);
    Card* comp_card = deal(deck);

    clear_screen();
    printf("Your card: ");
    display_card(player_card);

    unsigned num = 0;

    while (num == 0 || num > player_balance || num > computer_balance) {
        printf("\nYour balance: %d.  P2 balance: %d.\n", player_balance, computer_balance);
        printf("How much would you like to bet? ");
        scanf("%d", &num);
    }

    printf("\nPlayer 2's card: ");
    display_card(comp_card);


    // No winners.
    if (player_card->rank == comp_card->rank) {
        return 0;
    }

    // Need special handling for aces.
    if (player_card->rank == 1) {
        return num;
    } else if (comp_card->rank == 1) {
        return num * -1;
    }

    if (player_card->rank > comp_card->rank) {
        return num;
    } else {
        return num * -1;
    }
}


int main() {
    CardDeck* deck = new_deck();
    shuffle(deck);

    unsigned player_balance = 100;
    unsigned computer_balance = 100;

    printf("Welcome to high card/low card.\n\n");

    while (player_balance > 0 && computer_balance > 0) {
        int amount_won = play_game(deck, player_balance, computer_balance);
        player_balance += amount_won;
        computer_balance -= amount_won;

        if (amount_won > 0) {
            printf("You won!\n\n");
        } else if (amount_won < 0) {
            printf("You lost.  Better luck next time.\n\n");
        } else {
            printf("Push.\n\n");
        }

        printf("Your balance: %d.  P2 balance: %d.\n\n", player_balance, computer_balance);
        if (player_balance > 0 && computer_balance > 0) {
            char choice = '0';
            do {
                printf("Would you like to play again? (Y/n)\n");
                // The space before %c prevents stray newlines from being read.
                scanf(" %c", &choice);
            } while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y');
            if (choice == 'N' || choice == 'n') {
                printf("Goodbye.\n");
                exit(0);
            }
        }
    }

    if (player_balance == 0) {
        printf("\n\n***PLAYER 2 HAS BANKRUPTED YOU***\n\n");
        printf("Better luck next time!\n");
    } else {
        printf("\n\nYOU HAVE WON IT ALL!!!\n\n");
        printf("Congratulations.\n");
    }
}

