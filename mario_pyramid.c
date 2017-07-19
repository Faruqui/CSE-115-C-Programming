#include <cs50.h>
#include <stdio.h>

void makePyramid(int h);


int main(void)
{
    printf("Height of pyramid: ");
    int h = get_int();
    
    makePyramid(h);
    
    return 0;
}

//function to print a pyramid of height h
void makePyramid(int h)
{
    for(int r=1; r<=h; r++)
    {
        for(int space=0; space<h-r; space++) //printing required number of 'space' after determing the current row
        {
        printf(" ");
        }

        for (int i=0; i<r; i++) //printing required number of # for the current row
        {
            printf("#");
        }
        
        printf("  "); //gap between two sides of the pyramid 
        
        for (int i=0; i<r; i++)  //printing required number of # on the other side for the current row 
        {
            printf("#");
        }
        
        printf("\n"); //line break after printing each row
    }
}