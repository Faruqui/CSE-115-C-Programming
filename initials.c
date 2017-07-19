#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitials(string name);


int main(void)
{
    printf("Type Your Name: ");
    string name = get_string();
    
    printInitials(name);
}


void printInitials(string name)
{
    if(name[0] != ' ')
    {
        printf("%c", toupper(name[0]));
    }
    
    for(int i=0, l=strlen(name); i<l; i++)
    {
        if(name[i] == ' ' && name[i+1] != ' ')
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}