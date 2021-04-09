#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printArray(int logicalSize, int array[]);
void checkArrayLimit(int allocSize, int logSize);
void removeFrom(int index, int arr[], int * logSize);
void addToArray(int value, int arr[], int * logSz, int allocSz);
void insertAt(int value, int index, int arr[], int * logSize, int allocSize);
void fillArrayWithUserGivenValues(int allocSize, int * logSize, int arr[], int numValues);


int main() {
    int logicalSize = 0;
    int allocSize = 1000;

    int arr[allocSize];

    for (int i = 0; i < 10; i++) {
        addToArray(1, arr, &logicalSize, allocSize);
    }
    printArray(logicalSize, arr); // [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    insertAt(-1, 0, arr, &logicalSize, allocSize);
    printArray(logicalSize, arr); // [-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    removeFrom(0, arr, &logicalSize);
    printArray(logicalSize, arr); // [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    return 0;
}

// exit(int errorlevel) is like return 0, 1, 42 in main. So, if exit is called
// from anywhere  within the codebase it exits (or returns from) the main function
// with the errorlevel.
void checkArrayLimit(int allocSize, int logSize) {
    if (allocSize == logSize) {
        printf("Error: Max size reached!\n");
        exit(1);
    }
}

// Adds to the end of the array, only if the logical size is less than
// the allocated size. Here, end means the logical end of the array.
// Think about it!
void addToArray(int value, int arr[], int * logSz, int allocSz) {
    checkArrayLimit(allocSz, *logSz);
    arr[(*logSz)++] = value;    // This is tricky. This is post increment because
                                // the ++ is after the variable. Meaning, it is update
                                // the arr with *logSz, then it will update the value of
                                // (*logSize) by 1. The brackets are necessary due to precedence!
}


// Fills the array with n integers. Proactively, checks to see if max allocation size
// can hold or not. Updates the arr using pass by reference.
void fillArrayWithUserGivenValues(int allocSize, int * logSize, int arr[], int n) {
    int logSizeAfterInputs = *logSize + n;
    checkArrayLimit(allocSize, logSizeAfterInputs);
    for (; *logSize < logSizeAfterInputs; (*logSize)++) {
        printf("Please enter an integer: ");
        scanf("%d", &arr[(*logSize)]);
    }
}


// Prints the array.
void printArray(int logicalSize, int array[]) {
    printf("[");
    for (int i = 0; i < logicalSize; i++) {
        printf("%d", array[i]);
        if (i < logicalSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


// TO DO:
// Reference: http://stackoverflow.com/questions/859770/on-a-dereferenced-pointer-in-c
// It inserts an integer at the index position of the array. However before inserting
// it shifts all the previous int values to the right, PROVIDED the the allocation limit
// does not exceed.
void insertAt(int value, int index, int arr[], int * logSize, int allocSize) 
{
    
    checkArrayLimit(allocSize, *logSize);

    for(int i = *logSize; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
    
    *logSize = *logSize + 1;
    
}

// TO DO:
// It removes an integer from the index position of the array. However
// before removing it shifts all the previous int values to the left.
void removeFrom(int index, int arr[], int * logSize) 
{
    for(int i = index; i < *logSize; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    *logSize = *logSize - 1;
}