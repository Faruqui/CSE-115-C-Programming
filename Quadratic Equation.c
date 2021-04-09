#include <stdio.h>
#include <cs50.h>
#include <math.h>

float calculateD(float a, float b, float c);
void findRoot(float a, float b, float c);

int main(void){

    printf ("Type value of a: ");
    float a = get_float();

    printf ("Type value of b: ");
    float b = get_float();

    printf ("Type value of c: ");
    float c = get_float();

    findRoot(a, b, c);
    
    return 0;
}

//function to find the root
void findRoot(float a, float b, float c)
{
    float d = calculateD(a, b, c);
    
    if(a == 0)
    {
        printf("Error, value of a can not be zero\n");
    }


    if (d > 0 && a != 0)
    {
        float x1 = (-b + sqrt(d))/(2*a);
        float x2 = (-b - sqrt(d))/(2*a);

        printf ("x1 is %f\nx2 is %f\n", x1, x2);
    }
    else if (d == 0 && a != 0)
    {
        float x1 = (-b)/(2*a);
        float x2 = (-b)/(2*a);
        printf ("x1 is %f\nx2 is %f\n", x1, x2);
    }
    else
    {
        if(a != 0)
        {
        float real = (-b)/(2*a);
        float imaginary = (sqrt(fabs(d)))/(2*a);

        printf ("x1 is %f + i %f\nx2 is %f - i %f\n", real, imaginary, real, imaginary);
        }
    }
}

//function to find the value of d
float calculateD(float a, float b, float c)
{
    float d = b*b -4*a*c;
    return(d);
}