#include <stdio.h>
#include <cs50.h>

void drawHollowSquare(int n);


int main(void)
{
    printf ("Length of one side of hollow square: ");
    int n = get_int();
    
    drawHollowSquare(n);
    return 0;
}


void drawHollowSquare(int n)
{
    for(int r=0; r<n; r++) 
    {
        for(int c=0; c<n; c++)
        {
            if(r == 0 || r == n-1 || c == 0 || c == n-1) // checking condition and printing # if applicable 
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n"); //line break after printing each row
    }
}