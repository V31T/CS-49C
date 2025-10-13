#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

enum SquareStatus {
    EMPTY,
    P1,
    P2
};

enum GameStatus {
    PLAYING,
    OCCUPIED_SQUARE_ERR,
    INVALID_MOVE_ERR,
    P1_WINS,
    P2_WINS,
    CATS_GAME,
};

/**
 * Print out character to represent the state of the square.
 */
char decode(enum SquareStatus stat) {
    switch (stat) {
        case EMPTY:
            return ' ';
        case P1:
            return 'X';
        case P2:
            return 'O';
        default:
            return '?';
    }
}

/**
 * Clears the screen.
 */
void clear_screen() {
    printf("\e[1;1H\e[2J");
}

/**
 * If there is an error, this method prints out an error message
 * and then resets the GameStatus to "PLAYING".
 *
 * If there is not an error, the state is left unchanged.
 */
void print_error(enum GameStatus *gs){
    switch (*gs) {
        case OCCUPIED_SQUARE_ERR:
            printf("Sorry, that space is already occupied.  Please try again.\n");
            *gs = PLAYING;
            break;
        case INVALID_MOVE_ERR:
            printf("Sorry, that move is invalid.  Please try again.\n");
            *gs = PLAYING;
            break;
        default:
            // Handling other game status states to avoid warnings.
            break;
    }
}

/**
 * Prints out the tic-tac-toe board in text forat.
 */
void print_board(short board[BOARD_SIZE][BOARD_SIZE], enum GameStatus *gs) {
    clear_screen();
    print_error(gs);
    printf("\n    1   2   3  ");
    printf("\n  -------------\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d | ", i+1);
        for (int j=0; j<BOARD_SIZE; j++) {
            enum SquareStatus stat = board[i][j];
            char c = decode(stat);
            printf("%c | ", c);
        }
        printf("\n  -------------\n");
    }
}

/**
 * Checks whether the specified player has won the game.
 */
bool player_wins(enum SquareStatus player, short board[BOARD_SIZE][BOARD_SIZE]) {
    // Check each row for a win
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] != player) break;
            if (j == BOARD_SIZE-1) return true;
        }
    }

    //
    // **YOUR CODE HERE**
    //
    // Check to see if the specified player has been able to
    // get 3 in a row for any column, or for either diagonal.

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        bool win = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) { 
            return true;
        }
    }

    // Check main diagonal
    bool win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != player) {
            win = false;
            break;
        }
    }
    if (win) { 
        return true;
    }

    // Check anti-diagonal
    win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - 1 - i] != player) {
            win = false;
            break;
        }
    }
    if (win) { 
        return true;
    }

    return false;
}

/**
 * Prints out the final state of the board, adds a message about who won,
 * and exits the game.
 */
void display_winner_and_exit (short board[BOARD_SIZE][BOARD_SIZE], enum GameStatus *gs) {
    print_board(board, gs);

    //
    // **YOUR CODE HERE**
    //
    // Check the game status to see who won the game and print out
    // an appropriate message.
    //
    // Have fun with this part.  Look up the ANSI escape sequences
    // (https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797),
    // use ASCII art, etc.
    //
     printf("\n=====================\n");
    switch (*gs) {
        case P1_WINS:
            printf("You win!\n");
            break;
        case P2_WINS:
            printf("You lose :(\n");
            break;
        case CATS_GAME:
            printf("draw!\n");
            break;
        default:
            printf("Game ended unexpectedly.\n");
            break;
    }
    printf("=====================\n\n");

    exit(0);
}

/**
 * This function handles both checking for the end of the game and making
 * a move for the computer player.
 */
void comp_move(short board[BOARD_SIZE][BOARD_SIZE], enum GameStatus *gs) {
    //
    // **YOUR CODE HERE**
    //
    // First, check the board to see if player 1 has already won.
    // If so, set the GameStatus to P1_WINS and call
    // display_winner_and_exit to end the game.
    //
    // Do something similar to declare a cat's game (a draw) if there
    // are no legal moves left.
    //
    // If the game is not over, choose a move for the computer.  For
    // a simple option, you can choose a free square at random using the
    // 'rand' function.  (If you use this approach, make sure that
    // you have called 'srand' previously (only once) to seed the random
    // sequence.
    //
    // If the computer player makes a legal move, check to see if it is
    // a winning move; end the game if so.  Note that you do not need to
    // check if it is a cat's game since the human player will always get
    // the last move.
    //
       // First, check if P1 has already won
    if (player_wins(P1, board)) {
        *gs = P1_WINS;
        display_winner_and_exit(board, gs);
    }

    // Check for cat's game (full board, no winner yet)
    bool full = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                full = false;
                break;
            }
        }
    }
    if (full) {
        *gs = CATS_GAME;
        display_winner_and_exit(board, gs);
    }

    // computer picks rand entry
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;

    while (board[row][col] != EMPTY) {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    }

    board[row][col] = P2;  // computer move

    // Check if computer just won
    if (player_wins(P2, board)) {
        *gs = P2_WINS;
        display_winner_and_exit(board, gs);
    }
}

int main() {

    srand(032303);      // for debugging

    // Unlike in Java, an array is NOT automatically initialized to all zeroes.
    short board[BOARD_SIZE][BOARD_SIZE] = {{0,0,0}, {0,0,0}, {0,0,0}};

    enum GameStatus game_stat = PLAYING;

    do {
        print_board(board, &game_stat);

        printf("Enter your move (ROW COL): ");
        short row, col;
        scanf("%hd %hd", &row, &col);

        // Adjusting to indices
        row--;
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            game_stat = INVALID_MOVE_ERR;
        } else if (board[row][col] != EMPTY) {
            game_stat = OCCUPIED_SQUARE_ERR;
        } else {
            board[row][col] = P1;
            comp_move(board, &game_stat);
        }
    } while (true);
}