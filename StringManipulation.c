#include <stdio.h>
#include <string.h>
#include <ctype.h>

int linearSearch(char key, char* s);
void removeNumbers(char* s);
void removeVowels(char* s);

int main(void)
{
    char s[50]= "CSE 115 Sec 22 MEK";

    printf("%s\n", s);
    
    removeNumbers(s);
    removeVowels(s);
    
    printf("%s\n", s);
}

void removeVowels(char* s)
{
    char* vowel = "aeiou";
    int n = strlen(s);
    
    for(int i = 0; i < n; i++)
    {
        if(linearSearch(s[i], vowel))
        {
            s[i] = '#';
        }
    }
}

void removeNumbers(char* s)
{
    char* num = "1234567890";
    int n = strlen(s);
    
    for(int i = 0; i < n; i++)
    {
        if(linearSearch(s[i], num))
        {
            s[i] = '#';
        }
    }
}

int linearSearch(char key, char* s)
{
    int n = strlen(s);
    
    for(int i = 0; i < n; i++)
    {
        if(toupper(key) == toupper(s[i]))
        {
            return 1;
        }
    }
    return 0;
}