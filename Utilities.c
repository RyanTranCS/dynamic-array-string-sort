#include <string.h>
#include <stdlib.h>

void Swap(char **p1, char **p2);

/**
 * This method removes the newline characters from an array of strings returned by fgets().
 * 
 * routine: RemoveNewlineChars
 * 
 * return type: void
 * 
 * parameters:
 *  array          [char*]    the array to be sorted
 *  arrayLength    int        the length of the array
 * 
 * @author Ryan Tran
 * @since 2/11/2021
 * */

void RemoveNewlineChars(char *array[], int arrayLength) {
        for (int i = 0; i < arrayLength - 1; i++) {
        size_t len = strlen(array[i]);
        array[i][len - 1] = '\0';
    }
}

/**
 * This method sorts an array containing strings in ascending order using a traditional bubble sort sorting algorithm.
 * 
 * routine: BubbleSort
 * 
 * return type: void
 * 
 * parameters:
 *  array          [char*]    the array to be sorted
 *  arrayLength    int        the length of the array
 * 
 * @author Ryan Tran
 * @since 2/11/2021
 * */

void BubbleSort(char *array[], int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        for (int j = 0; j < arrayLength - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                Swap(&array[j], &array[j + 1]);
            }
        }
    }
}

/**
 * This method swaps pointers.
 * 
 * routine: swap
 * 
 * return type: void
 * 
 * parameters:
 *  p1    char**    address of the first pointer to be swapped
 *  p2    char**    address the second pointer to be swapped
 * 
 * @author Ryan Tran
 * @since 2/11/2021
 * */

void Swap(char **p1, char **p2) {
    char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/**
 * This method frees the memory of an array of pointers.
 * 
 * routine: FreeArrayOfPointers
 * 
 * return type: void
 * 
 * parameters:
 *  array           [char*]     the array to be freed
 *  arrayLength     int         the length of array
 * 
 * @author Ryan Tran
 * @since 2/11/2021
 * */

void FreeArrayOfPointers(char *array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        free(array[i]);
    }
}
