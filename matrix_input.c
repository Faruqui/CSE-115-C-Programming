/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


void printMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            printf("%i\t", mat[r][c]);
        }
        printf("\n");
    }
}

void generateMatrix(int row, int col, int mat[row][col]) {
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            int a;
            printf("Enter radius for position (%d,%d): ", r + 1, c + 1);
            scanf("%d", &mat[r][c]);
        
        }
    }
}

void readMatrixAndStore(int row, int col, int mat[row][col]){
    FILE *fp = NULL;
    fp = fopen("data.csv", "w");
    int serial = 1;
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            fprintf(fp, "a) %d\t", serial);
            int radius = mat[r][c];
            float area = M_PI * mat[r][c] * mat[r][c];
            float parameter = 2 * M_PI * mat[r][c];
            fprintf(fp, "b)%d\tc) %f\t d) %f\t \n", radius, area, parameter);
            serial++;
        }
        
    }
}



int main()
{   
    int row = 2;
    int col = 2;
    int mat[row][col];
    generateMatrix(row, col, mat);
    printMatrix(row, col, mat);
    
    readMatrixAndStore(row, col, mat);
}


    
