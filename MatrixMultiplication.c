#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LIMIT = 30;

int randomNumberGenerator(int limit);
void setRandomSeed(unsigned int seed);
void getRowColFromUser(int * row, int * col);
void randMatrix(int row, int col, int mat[row][col]);
void printMatrix(int row, int col, int mat[row][col]);
void getTwoValidMatrixForMult(int * row1, int * col1, int * row2, int *col2);
void multMatrix(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int resMat[r1][c2]);

int main() {

    int row1, col1, row2, col2;
    getTwoValidMatrixForMult(&row1, &col1, &row2, &col2);

    setRandomSeed(10);
    int result[row1][col2];
    int matrix_1[row1][col1];
    int matrix_2[row2][col2];

    printf("\nGenerated a random matrix A: \n");
    randMatrix(row1, col1, matrix_1);
    printMatrix(row1, col1, matrix_1);

    printf("\nGenerated a random matrix B: \n");
    randMatrix(row2, col2, matrix_2);
    printMatrix(row2, col2, matrix_2);

    printf("\nThe multiplication: C = A x B \n");
    multMatrix(row1, col1, matrix_1, row2, col2, matrix_2, result);
    printMatrix(row1, col2, result);
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

// generates a random matrix
void randMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            mat[r][c] = randomNumberGenerator(MAX_LIMIT);
        }
    }
}

// prints the matrix
void printMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            printf("%i\t", mat[r][c]);
        }
        printf("\n");
    }
}


// Get the matrix row and col dimension info from console.
void getRowColFromUser(int * row, int * col) {
    printf("Please enter the row and col (as integers) [use space as separator]: ");
    scanf("%d %d", row, col);
}

// Get two valid multiplicable matrix dimension from user.
void getTwoValidMatrixForMult(int * row1, int * col1, int * row2, int *col2) {
    while (1) {
        printf("Please enter the dimensions for the matrix 1. ");
        getRowColFromUser(row1, col1);

        printf("Please enter the dimensions for the matrix 2. ");
        getRowColFromUser(row2, col2);

        if (*col1 == *row2) break;
        printf("\nError! Column of the first matrix does not equal to row of second.\n\n");
    }
}


// TO DO: Complete the matrix multiplier function!
void multMatrix(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int resMat[r1][c2]) 
{
    if(c1 == r2)
    {
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                int sum = 0;
                for(int k = 0; k < c2; k++)
                {
                    sum = sum + mat1[i][j] * mat2[j][k];
                }
                resMat[i][j] = sum;
            }
        }
    }
}