#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    printf("Type a positive number: ");
    int n = get_int();
    
    int f = factorial(n);
    
    printf("%i\n", f);
    
    return 0;
}

int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    
    int s = n * factorial(n-1);
    
    return s;
}