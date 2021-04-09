#include<stdio.h>
 
int Fibonacci(int);
 
int main(void)
{
   int n;
   printf("Enter number of terms in Fibonacci series: ");
   scanf("%d",&n);
 
   printf("Fibonacci series: ");
 
   for (int i = 0 ; i < n ; i++ )
   {
      printf("%d\t", Fibonacci(i));
   }
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 ) return 0;

   if ( n == 1 ) return 1;
   
   return ( Fibonacci(n-1) + Fibonacci(n-2) );
}