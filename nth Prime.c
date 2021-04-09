#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool isPrime(int n);
int nthPrime(int n);

int main(void)
{
    printf("Enter _th prime number: ");
    int n = get_int();
    
    int x = nthPrime(n);
    
    printf("%ith prime number is: %i\n", n, x);
}

//function to find nth prime number
int nthPrime(int n)
{
    int p = 2;
    int c = 0;
    
    while(c != n)
    {
        if(isPrime(p))
        {
            c++; //keep a count of prime numbers
        }
        p++; //Iterate through every number form 2
    }
    
    return (p-1);
}

//function to determine if an integer is a prime number or not
bool isPrime(int n)
{
    int a = 2;
    
    for(int i = 2; i < n; i++)
    {
        if( (n % i) == 0 )
        {
            return 0;
            break;
        }
        a++;
    }
    
    if( a == n )
    {
        return true;
    }
    else
    {    
        return 0;
    }
}