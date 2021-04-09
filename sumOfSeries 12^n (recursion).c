#include <stdio.h>
#include <math.h>

float sumOfSeries(int n);

int main(void)
{
    printf("Enter the value of n: ");
    int n;
    scanf("%i", &n);
    
    float sum = sumOfSeries(n);
    
    printf("Sum: %f\n", sum);
    
    return 0;
}

float sumOfSeries(int n)
{
    if(n == 0) return 1;
    
    return 1/(pow(2, n)) + sumOfSeries(n-1);
}