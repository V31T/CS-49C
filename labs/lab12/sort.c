#include <stdio.h>

/**
 * Returns a positive number to indicate that x should come before y
 * to create an ascending order.
 */
int asc(int x, int y) {
    return y - x;
}

/**
 * Returns a positive number to indicate that x should come before y
 * to create a descending order.
 */
int desc(int x, int y) {
    return x - y;
}

/**
 * Sort elements in the nums array.
 */
void sort(int* nums, int size) {
    //
    // **YOUR CODE HERE**
    //
    // Sort the list of numbers with the sorting algorithm of your choice.
    // Bubble sort is a fairly easy one to implement.
    //
    // After you have that working, introduce the following changes:
    //
    // 1) Create a SWAP(a,b) macro that will swap the values of
    //   variables a and b with each other.
    //
    // 2) Add a parameter for a function pointer that takes in two ints
    //   and returns a positive number if the first element should come first
    //   and a negative number if it should come second.  Update your
    //   algorithm to use this function pointer.

}

/**
 * Prints out the contents of an array.
 */
void print_arr(int* nums, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main() {
    int nums[] = { 22, 3, -5, 0, 18, 7, 99, 8, 42, 67, 2 };

    // Calculating the size of the array.
    // Note that this does not work with pointers.
    int size = (sizeof(nums) / sizeof(int));
    printf("The array has %d elements\n", size);

    //
    // **YOUR CODE HERE**
    //
    // Change the call to sort to use a function pointer.
    // (You will need to update the sort function first).
    // Use pointers to the 'asc' and 'desc' functions to
    // sort the array in both ascending and descending order.
    sort(nums, size);
    print_arr(nums, size);

    return 0;
}

