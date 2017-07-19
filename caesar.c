#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesar(int key, string text);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error, Need a numeric command line value\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    printf("Enter text to encrypt: ");
    string text = get_string();
    
    caesar(key, text);

    return 0;
    
}

//function to print caesar encrypted text using user given text and a cypher key
void caesar(int key, string text)
{
    if(text != NULL)
    {
        for(int i = 0, n = strlen(text); i < n; i++) //iterate through every letter
        {
            if(isupper(text[i])) //check if upper case letter and replace it by an alphabet after key no. of places
            {
                printf("%c", (((text[i] - 'A' + key) % 26) + 'A'));
            }
            
            else if(islower(text[i])) //check if lower case letter
            {
                printf("%c", (((text[i] - 'a' + key) % 26) + 'a'));
            }
            else //print non-alphabetic char like ' ',',','!' uncanged
            {
                printf("%c", text[i]);
            }
        }
    printf("\n");
    }
}