#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[50];
    char id[20];
    int score;
}
student;

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("data.csv", "w");
    
    printf("How many students: ");
    int n;
    scanf("%i", &n);
    
    student students[n];
    
    for(int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("ID: ");
        scanf("%s", students[i].id);
        
        printf("Score: ");
        scanf("%i", &(students[i].score));
        
        printf("\n");
    }
    
    for(int i = 0; i < n; i++)
    {
        fprintf(fp, "%s, %s, %i \n", students[i].name, students[i].id, students[i].score);
    }
    fclose(fp);
}