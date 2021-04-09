#include <stdio.h>

int sumOfDigits(int n);

int main(void)
{
    printf("Enter Number: ");
    int n;
    scanf("%i", &n);
    
    int s = sumOfDigits(n);
    printf("Sum of Digits: %i\n", s);
    
    return 0;
}

int sumOfDigits(int n)
{
    if(n == 0) return 0;
    
    return n%10 + sumOfDigits(n/10);
}