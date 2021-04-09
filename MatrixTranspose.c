#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LIMIT = 30;

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

void randMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            mat[r][c] = randomNumberGenerator(MAX_LIMIT);
        }
    }
}

// TO DO:
// Complete the following tranpose matrix function based on the how it is called in main.
void transposeTheMatrix(int row, int col, int matrix[row][col], int transposeMatrix[col][row]) { // please design the parameters accoring to how it is
                               // called in main. Remove this comment after implement
                               // -ation.
    for(int a = 0; a < row; a++)
    {
        for(int b = 0; b < col; b++)
        {
            transposeMatrix[b][a] = matrix[a][b];
        }
    }
}

void printMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            printf("%i\t", mat[r][c]);
        }
        printf("\n");
    }
}


void getRowColFromUser(int * row, int * col) {
    printf("Please enter the row and col (as integers) [use space as separator]: ");
    scanf("%d %d", row, col);
}

int main() {

    int row, col;
    getRowColFromUser(&row, &col);

    // prepare the space for the ip and out matrices.
    int matrix[row][col];
    int transposeMatrix[col][row];

    setRandomSeed(10); // setting the random seed.
    randMatrix(row, col, matrix);
    printf("Original matrix: \n");
    printMatrix(row, col, matrix);

    printf("\n");


    transposeTheMatrix(row, col, matrix, transposeMatrix);
    printf("Transpose matrix: \n");
    printMatrix(col, row, transposeMatrix);
    return 0;
}