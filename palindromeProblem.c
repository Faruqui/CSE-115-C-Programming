#include <stdio.h>
#include <string.h>

int isPalindrome(char input[]);
void getTheString(char input[]);
void printPalindromeState(char input[]);

int main() {
    int size = 100;
    char text[size];

    getTheString(text);
    printPalindromeState(text);

    return 0;
}

void getTheString(char input[]) {
    printf("Please enter the text to check for palindrome (max 99 chars): ");
    //gets(input);
    scanf("%s", &input[0]);
}

void printPalindromeState(char input[]) {
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
}

// TO DO: Implement the palindrome function. If the input
// is a palindrome, return 1 else return 0.
int isPalindrome(char input[]) 
{
    int n = strlen(input);
    int m = n/2;
    
    for(int i = 0; i < m; i++)
    {
        if(input[i] != input[n - 1])
        {
            return 0;
        }
        n--;
    }
    return 1;
}