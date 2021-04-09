#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int crackPassword(char* hash, char* salt);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error! Need hash code.\n");
        return 1;
    }
    
    char* hash = argv[1];
    char salt [3] = { hash[0], hash[1], '\0' }; //get salt from hash code
    
    crackPassword(hash, salt);
    
    return 0;
}    

//function to find password from hash code
int crackPassword(char* hash, char* salt)
{
    char start = 'A'; //Initial ascii character
    char end = 'z'; //Final ascii character
    
    // for 1 letter pass iterate all values of 1 character
    for(char first = start; first <= end; first++) 
    {
        char tmp[5];
        tmp[0] = first;
        tmp[1] = '\0';
        
        if(!strcmp(crypt(tmp, salt), hash)) //check for 1 letter password
        {
            printf("Password is: %s\n", tmp);
            return 0;
        }
        
        //for 2 letter password iterate all values of 2 letter word
        for(char second = start; second <= end; second++)
        {
            tmp[0] = first;
            tmp[1] = second;
            tmp[2] = '\0';
            
            if(!strcmp(crypt(tmp, salt), hash)) //check for 2 letter password
            {
                printf("Password is: %s\n", tmp);
                return 0;
            }
            
            //for 3 letter password iterate all values of 3 letter word
            for(char third = start; third <= end; third++)
            {
                tmp[0] = first;
                tmp[1] = second;
                tmp[2] = third;
                tmp[3] = '\0';
                
                if(!strcmp(crypt(tmp, salt), hash)) //check for 3 letter password
                {
                    printf("Password is: %s\n", tmp);
                    return 0;
                }
                
                //for 4 letter password iterate all values of 4 letter password
                for(char fourth = start; fourth <= end; fourth++)
                {
                    tmp[0] = first;
                    tmp[1] = second;
                    tmp[2] = third;
                    tmp[3] = fourth;
                    tmp[4] = '\0';
                    
                    if(!strcmp(crypt(tmp, salt), hash)) //check for 4 letter password
                    {
                        printf("Password is: %s\n", tmp);
                        return 0;
                    }
                }
            }
        }
        
    }
    printf("Invalid Hash!\n");
    return 1;
}