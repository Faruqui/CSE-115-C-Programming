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

float getAverageGrade(int allocSize, int logicalSize, student array[]);
student getBestStudent(int allocSize, int logicalSize, student array[]);
student getWorstStudent(int logicalSize, student array[]);

int main(void)
{
    int logicalSize = 0;
    int allocSize = 1000;
    
    student s[allocSize];
    
    FILE *fp = fopen("data.csv", "r");
    
    if(fp != NULL)
    {
        while(1)
        {
            if(feof(fp)) break;
            fscanf(fp, "%[^,],%[^,], %i", s[logicalSize].name, s[logicalSize].id, &(s[logicalSize].score));
            //fscanf(fp, "%s,%s, %i", s[logicalSize].name, s[logicalSize].id, &(s[logicalSize].score));
            logicalSize++;
        }
        logicalSize--;
        fclose(fp);
    }
    
    printf("logical size: %i\n", logicalSize);
    
    float avg = getAverageGrade(allocSize, logicalSize, s);
    printf("Average Score: %f\n", avg);
    
    student bestStudent = getBestStudent(allocSize, logicalSize, s);
    printf("Best Student: %s Score: %i\n", bestStudent.name, bestStudent.score);
    
    student worstStd = getWorstStudent(logicalSize, s);
    printf("Worst Student: %s Score: %i\n", worstStd.name, worstStd.score);
}

float getAverageGrade(int allocSize, int logicalSize, student array[])
{
    float sum = 0;
    if(logicalSize <= allocSize)
    {
        for(int i = 0; i < logicalSize; i++)
        {
            sum = sum + array[i].score;
        }
    }
    return sum/(logicalSize);
}

student getBestStudent(int allocSize, int logicalSize, student array[])
{
    student bestStd = array[0];
    if(logicalSize <= allocSize)
    {
        for(int i = 0; i < logicalSize; i++)
        {
            if(bestStd.score < array[i].score)
            {
                bestStd = array[i];
            }
        }
    }
    return bestStd;
}

student getWorstStudent(int logicalSize, student array[])
{
    student worstStd = array[0];
    for(int i = 0; i < logicalSize; i++)
    {
        if(worstStd.score > array[i].score)
        {
            worstStd = array[i];
        }
    }
    return worstStd;
}