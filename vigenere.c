#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere(char* text, char* key);

int main(int argc, string argv[])
{
    if(argc != 2) //send error if the argument count is not 2
    {
        printf("Error, Need a alphabetic command line input\n");
        return 1;
    }
    
    char* key = argv[1];
    
    printf("Enter text to cypher: ");
    char* text = get_string();
    
    if(text == NULL)
    {
        return 1;
    }
    
    vigenere(text, key);
    
    return 0;
}


//function to print vignere encrypted text using user given text and a cypher key
void vigenere(char* text, char* key)
{
    int keylen = strlen(key); //set the string length of the key
    
    for(int i = 0, n = strlen(text); i < n; i++) //iterate through every character of the text
    {
        if(isalpha(text[i])) // change the alpabetic character as per the key
        {
            if(isupper(text[i])) //upper case alpabet requires upper case key
            {
                //key[i % keylen] will iterate through the letters of the key for as many times as required
                printf("%c", ((text[i] - 'A' + toupper(key[i % keylen]) - 'A') % 26) + 'A' ); 
            }
            else //lower case alphabet require lower case key 
            {
                printf("%c", ((text[i] - 'a' + tolower(key[i % keylen]) - 'a') % 26) + 'a' );
            }
        }
        else
        {
            printf("%c", text[i]); // print non-alphabetic character unchanged 
        }
    }
    printf("\n");
}