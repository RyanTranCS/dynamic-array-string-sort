/**
 * This program stores the string values contained within a text file in a dynamic array, sorts the array, and prints
 * the sorted strings in a separate text file.
 * 
 * Assumptions: 
 * Strings will not contain more than 100 characters.
 * 
 * CSC 3304 Programming Project No. 3
 * 
 * @author Ryan Tran
 * @since 2/18/2021
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilities.h"

#define MAX_STR_LENGTH 100

int main() {
    FILE *inFile = fopen("./TestInput.txt", "r");   // pointer to text file containing strings
    if (!inFile) {
        printf("Error Opening File: Exiting Program");
        return 1;
    }

    int arrayLength = 10;                                   // initial array size 

    char **linePtrs = malloc(sizeof(char*) * arrayLength);  // array initially containing memory for 10 char*
    if (!linePtrs) {
        printf("Memory Allocation Error: Exiting Program");
        return 1;
    }

    int index = 0;                                          // array indexer
    int numElements = 0;                                    // number of array elements

    linePtrs[index] = malloc(MAX_STR_LENGTH);  // memory allocation for to-be-read string of unknown length
    if (!linePtrs[index]) {
        printf("Memory Allocation Error: Exiting Program");
        return 1;
    }

    while (fgets(linePtrs[index], MAX_STR_LENGTH, inFile) != NULL) {
        numElements++;

        int strLenWithNullChar = strlen(linePtrs[index]) + 1;

        // shrinks memory after knowing string length
        char* temp = realloc(linePtrs[index], strLenWithNullChar);
        if (!temp) {
            printf("Memory Reallocation Error: Freeing Memory and Exiting Program");
            FreeArrayOfPointers(linePtrs, numElements);
            return 1;
        }
        linePtrs[index] = temp;

        // doubles array length/size when full
        if (numElements == arrayLength) {
            arrayLength = arrayLength * 2;
            char **temp = realloc(linePtrs, sizeof(char*) * arrayLength);
            if (!temp) {
                printf("Memory Reallocation Error: Freeing Memory and Exiting Program");
                FreeArrayOfPointers(linePtrs, numElements);
                return 1;
            }
            linePtrs = temp;
        }

        // allocates memory for next string
        linePtrs[index + 1] = malloc(MAX_STR_LENGTH);
        if (!linePtrs[index + 1]) {
            printf("Memory Allocation Error: Freeing Memory and Exiting Program");
            FreeArrayOfPointers(linePtrs, numElements);
            return 1;
        }
        index = index + 1;
    }

    fclose(inFile);
    free(linePtrs[index]);  // frees extra allocated memory after the last element

    arrayLength = numElements;  // optimized array length/size
    
    // shrinks array to optimized array length/size
    char **temp = realloc(linePtrs, sizeof(char*) * arrayLength);
    if (!temp) {
        printf("Memory Reallocation Error: Freeing Memory and Exiting Program");
        FreeArrayOfPointers(linePtrs, numElements);
        return 1;
    }
    linePtrs = temp;

    RemoveNewlineChars(linePtrs, numElements);
    BubbleSort(linePtrs, numElements);

    FILE *outFile = fopen("./out.txt", "w");    // pointer to text file which sorted strings will be printed to
    if (!outFile) {
        printf("Error Opening File: Freeing Memory and Exiting Program");
        FreeArrayOfPointers(linePtrs, numElements);
        return 1;
    }

    // prints array elements with a newline character to text file
    for (int i = 0; i < numElements - 1; i++) {
        fputs(linePtrs[i], outFile);
        fputs("\n", outFile);
    }
    fputs(linePtrs[numElements - 1], outFile);

    fclose(outFile);

    FreeArrayOfPointers(linePtrs, numElements);

    return 0;
}
