#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LIMIT = 30;

void printProgramInfo();
void checkSearchLimit(int i, int n);
int randomNumberGenerator(int limit);
void setRandomSeed(unsigned int seed);
void getRowColFromUser(int * row, int * col);
int findLowerMat(int r, int c, int mat[r][c]);
int isLowerMat(int row, int col, int mat[row][col]);
void randMatrix(int row, int col, int mat[row][col]);
void printMatrix(int row, int col, int mat[row][col]);

int main() {

    int row, col;
    printProgramInfo();
    getRowColFromUser(&row, &col);

    setRandomSeed(10);
    int matrix[row][col];
    int count = findLowerMat(row, col, matrix);
    printf("Computer generated %d matrices to find the matrix: \n", count);
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

void randMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            mat[r][c] = randomNumberGenerator(MAX_LIMIT);
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


int isLowerMat(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            if ((c < r) && mat[r][c]!=0)
                return 0;
        }
    }
    return 1;
}

int isUpperMat(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            if ((r < c) && mat[r][c]!=0)
                return 0;
        }
    }
    return 1;
}

void checkSearchLimit(int i, int n) {
    if(i > pow(2, n-1)) {
        printf("Searched %d matrices! Aboting! Try again!\n", i);
        exit(1);
    }
}

int findLowerMat(int r, int c, int mat[r][c]) {
    int count = 0;
    while(1) {
        randMatrix(r, c, mat);
        if(isLowerMat(r, c, mat)) return count + 1;
        int limit = (sizeof(int) * 8)/2;
        checkSearchLimit(count, limit);
        count++;
    }
}



void printProgramInfo() 
{
    printf("This program finds a unique lower triangular matrix.\n");
}