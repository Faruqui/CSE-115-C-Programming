#include <cs50.h>
#include <stdio.h>
#include <math.h>

int calcCoins(float n);

int main(void)
{
    float change;

    printf("How much change do I owe you in dollars? ");
    change = get_float();

    
    int coins = calcCoins(change);
    
    printf("%i\n", coins);
    
    return 0;
}

//funtion to calculate the number of coins
int calcCoins(float n)
{
    int coins[4] = {25, 10, 5, 1};
    int sum = 0;
    
    int cents = (n * 100);
    
    for(int i=0; i<4; i++) //iterate through all 4 coins
    {
        sum = sum + cents/coins[i];
        cents = cents%coins[i]; //change cents to the remainder
    }
    
    return sum;
}
