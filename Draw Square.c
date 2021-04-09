#include <stdio.h>
#include <cs50.h>

void drawSquare(int n);
void printLine(int n);


int main(void)
{
    printf ("Length of one side of square:");
    int n = get_int();
    
    drawSquare(n);
    return 0;
}

//function to draw square of n side length
void drawSquare(int n)
{
    for (int i=0; i<n; i++)
    {
        printLine(n);
    }
}

//function to draw a single line of n length
void printLine(int n)
{
    for (int i=0; i<n; i++)
    {
        printf("#");
    }
    printf("\n");
}