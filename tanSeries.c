#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
    printf("Enter the value of n: ");
    int n;
    scanf("%i", &n);
    
    printf("Enter the value of x: ");
    float x;
    scanf("%f", &x);
    
    float sum = 0;
    
    for(int i = 1; i <= n; i++)
    {
        sum = sum + (pow(i, i) / tan((pow(x, i))*PI/180)); //tan function works with radian angle
    }
    
    float y = tan(n * PI/180);
    
    printf("%f, %f \n", sum, y);
}