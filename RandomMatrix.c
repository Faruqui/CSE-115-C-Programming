#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LIMIT = 30;

int randomNumberGenerator(int limit);
void setRandomSeed(unsigned int seed);
void randMatrix(int row, int col, int mat[row][col]);
void printMatrix(int row, int col, int mat[row][col]);

int main() {
    int row = 5, col = 4;
    int matrix[row][col];

    setRandomSeed(10); // setting the random seed.
    printf("Original matrix: \n");
    randMatrix(row, col, matrix);
    printMatrix(row, col, matrix);


    return 0;
}


// Sets the seed for the random number generator. If this function is not called,
// random generator will always generate random number. However, if a seed is
// initiated then, the for that seed integer value the random numbers that are ge-
// nerated will always be the same. Play with this a bit to understand more.
// Check with Google! Or if you are super lazy, ask me in class.
void setRandomSeed(unsigned int seed) {
    srand(seed);
}

// Generated a random integer between 0 and limit (exclusive)
int randomNumberGenerator(int limit) {
    return rand() % limit;
}

// TO DO.
// Generated a random matrix of size row and col.
// Where the limit is MAX_LIMIT which is defined as
// global constant.
void randMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            mat[r][c] = randomNumberGenerator(MAX_LIMIT);
        }
    }
}

// prints a matrix of size row and col using tabs
void printMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            printf("%d\t", mat[r][c]);
        }
        printf("\n\n");
    }
}