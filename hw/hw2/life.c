#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LIVE "*"
#define DEAD "."

#define DEFAULT_WIDTH 40
#define DEFAULT_HEIGHT 20

// Times are in microseconds
#define SLOW_SLEEP_TIME 2000000
#define MED_SLEEP_TIME   500000
#define FAST_SLEEP_TIME   50000

/**
 * Prints out the board in text.
 *
 * Note that this function uses a C99 compatible feature for
 * specifying the second dimension of the 2-dimensional array.
 */
void display_grid(int height, int width, char grid[][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (grid[i][j] == 1) {
                printf(LIVE);
            } else {
                printf(DEAD);
            }
        }
        printf("\n");
    }
}

/**
 * Rules of life:
 * 1) Any live cell with two or three live neighbours survives.
 * 2) Any dead cell with three live neighbours becomes a live cell.
 * 3) All other live cells die in the next generation.
 *    Similarly, all other dead cells stay dead
 *
 * Treat any cells from outside of the grid as dead.
 */
bool is_alive(int y_pos, int x_pos, int height, int width, char grid[][width]) {
    int live_count = 0;
    for (int i=y_pos-1; i<=y_pos+1; i++) {
        for (int j=x_pos-1; j<=x_pos+1; j++) {
            if (i<0 || j<0 || i>=height || j>=width) {
                // Do nothing, for simplicity.
                // We could try to wrap around the array
                // and perform the calculation using those cells,
                // which is what many implementations do.
            } else if (i==y_pos && j==x_pos) {
                // Skip this one as well.
                // The cell's own live/dead status
                // is dealt with later.
            } else {
                live_count += grid[i][j];
            }
        }
    }

    if (grid[y_pos][x_pos]) {
        // Cell is currently alive.
        return live_count == 2 || live_count == 3;
    } else {
        // Cell is currently dead.
        return live_count == 3;
    }
}

/**
 * Go through the grid and update each cell to be true if alive
 * or false if dead, based on the status of the last round.
 */
void update_grid(int height, int width, char in[][width]) {
    char out[height][width];
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            out[i][j] = is_alive(i, j, height, width, in);
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            in[i][j] = out[i][j];
        }
    }
}

/**
 * Clears the screen so that new output can be displayed.
 */
void clear_screen() {
    printf("\e[1;1H\e[2J");
}

/**
 * Runs the simulation forever.
 */
void run_simulation(int height, int width, char grid[][width], unsigned sleep_time) {
    //
    // **YOUR CODE HERE**
    //
    // On a loop, clear the screen, display the grid, sleep, and update the grid
    // with the new live/dead information based on the previous state of the grid.
    // (You might need to make a copy of the grid.)
    //

    // NOTE: pdate_grid already makes a local copy internally (out[][]),
    // so we can call it directly without copying here.
    while (true) {
        clear_screen();               // clear old frame
        display_grid(height, width, grid); // print current frame
        usleep(sleep_time);           // pause so we can see it (time in microseconds)
        update_grid(height, width, grid);  // compute next frame
    }
}

/**
 * Set every cell in the grid to be either alive or dead
 * with equal probability.
 */
void rand_fill(int height, int width, char grid[][width]) {
    //
    // **YOUR CODE HERE**
    //
    // Randomly assign every cell of the grid to be either alive or dead
    // with equal probability.
    //
    // Remember to seed your random function.
    //
    // Seed once (time-based). Doing it here is fine since rand_fill
    // is called once from main for the random-mode.
    srand((unsigned) time(NULL)); // seed RNG, otherwise it's the same every run — boring

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // 50/50 chance of alive (1) or dead (0)
            grid[i][j] = (rand() % 2) ? 1 : 0;
        }
    }
}

/**
 * Read in the file specified.  Store the height and width in the specified
 * int pointers.
 */
void calc_grid_dimensions(int* height, int* width, char* file_name) {
    //
    // **YOUR CODE HERE**
    //
    // Read in the file and set the height and width.
    //
    // Only consider the characters '.', '*', 'X', or 'O' when calculating
    // the width.  Ignore whitespace.
    //
    // For height, only count the lines where there is at lease one valid character.
    //
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening pattern file");
        exit(1);
    }

    int max_width = 0;
    int curr_count = 0;
    int h = 0;
    int ch;
    bool line_has_valid = false;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            if (line_has_valid) {
                h++;
                if (curr_count > max_width) max_width = curr_count;
            }
            // reset counters for next line
            curr_count = 0;
            line_has_valid = false;
        } else {
            // consider only '.' '*' 'X' 'O' as valid pattern chars
            if (ch == '.' || ch == '*' || ch == 'X' || ch == 'O') {
                curr_count++;
                line_has_valid = true;
            } else {
                // ignore everything else (whitespace or other symbols)
            }
        }
        
    }

    // handle last line if file didn't end with newline
    if (line_has_valid) {
        h++;
        if (curr_count > max_width) max_width = curr_count;
    }

    fclose(fp);

    *height = h;
    *width = max_width;

    printf("width: %d \nheight: %d", *width, *height);
}

/**
 * Given the specified pattern file, set the cells in the grid to true for alive
 * or false for dead, as specified by the pattern.  In the file, the '.' character
 * is treated as dead, and the 'X', 'O', and '*' characters are considered alive.
 *
 * The width and height are assumed to be known before this function is called.
 */
void read_grid(char* file_name, int height, int width, char grid[][width]) {
    //
    // **YOUR CODE HERE**
    //
    // Read through the file and set the initial statue of each cell in the
    // grid to match the pattern, as specified in the comment on this method.
    //
    // fill rows left-to-right. If a row has fewer valid chars than
    // width, remaining cells become dead. If a row has more, extras are ignored.
    //

    // initialize everything dead first (helps with short rows)
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            grid[i][j] = 0;

    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening pattern file");
        exit(1);
    }

    int row = 0;
    int col = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF && row < height) {
        if (ch == '\n') {
            // move to next row if this row had any progress, or even if empty
            if (col > 0 || col == 0) {
                // make sure to fill rest with dead (already done)
                row++;
                col = 0;
            }
        } else if (ch == '.' || ch == '*' || ch == 'X' || ch == 'O') {
            if (col < width) {
                if (ch == '.' ) {
                    grid[row][col] = 0;
                } else {
                    // 'X', 'O', '*' counted as alive
                    grid[row][col] = 1;
                }
            }
            col++;
            // ignore extra valid chars beyond width
        } else {
            // ignore other chars (spaces, tabs, etc.)
        }
    }

    // if file didn't end with newline but we populated a row, advance row
    // (no need to fill remaining cells; already set to 0 at start)
    if (col > 0 && row < height) {
        row++;
    }

    fclose(fp);
}

/**
 * Run the simulation.
 */
int main(int argc, char* argv[]) {
    int c;

    int rand_flag = false;
    int file_flag = false;
    int fast_flag = false;
    int slow_flag = false;

    int w = DEFAULT_WIDTH;
    int h = DEFAULT_HEIGHT;

    char* file_name;

    while ((c = getopt(argc, argv, "rw:h:f:SF")) != -1) {
        switch (c) {
            case 'r':
                rand_flag = true;
                break;
            case 'w':
                w = atoi(optarg);
                break;
            case 'h':
                h = atoi(optarg);
                break;
            case 'f':
                file_flag = 1;
                file_name = optarg;
                break;
            case 'F':
                fast_flag = true;
                break;
            case 'S':
                slow_flag = true;
                break;
            case '?':
                if (optopt == 'w') {
                    fprintf(stderr, "Option w requires a positive number.\n");
                } else if (optopt == 'h') {
                    fprintf(stderr, "Option h requires a positive number.\n");
                } else if (optopt == 'f') {
                    fprintf(stderr, "Option f requires a file name.\n");
                } else {
                    fprintf(stderr, "Unknown option character %c.\n", optopt);
                }
                return 1;
            default:
                abort();
        }
    }

    if (w <= 0) {
        fprintf(stderr, "Width must be positive, but you specified %d.", w);
        return 1;
    } else if (h <= 0) {
        fprintf(stderr, "Height must be positive, but you specified %d.", h);
        return 1;
    }


    unsigned sleep_time;

    if (fast_flag && slow_flag) {
        fprintf(stderr, "Either -S or -F can be specified, but not both.\n");
        return 1;
    } else if (fast_flag) {
        sleep_time = FAST_SLEEP_TIME;
    } else if (slow_flag) {
        sleep_time = SLOW_SLEEP_TIME;
    } else {
        sleep_time = MED_SLEEP_TIME;
    }

    if (rand_flag) {
        char grid[h][w];
        rand_fill(h, w, grid);
        run_simulation(h, w, grid, sleep_time);
    } else if (file_flag) {
        // Resetting height and width to match grid.
        h = w = 0;
        calc_grid_dimensions(&h, &w, file_name);
        char grid[h][w];
        read_grid(file_name, h, w, grid);
        run_simulation(h, w, grid, sleep_time);
    } else {
        fprintf(stderr, "Either the -r or -f options must be specified.\n");
        return 1;
    }

    return 0;
}
