#include <math.h>
#include <stdio.h>

void swap(int *a, int *b);
void printArray(int logicalSize, int array[]);
void bubbleSort(int n, int arr[]);
void selectionSort(int n, int arr[]);

int main(void)
{
    int arr[9] = {5, 3, 9, 1, 2, 8, 4, 7, 6};
    
    printArray(9, arr);
    bubbleSort(9, arr);
    printArray(9, arr);
    
    printArray(9, arr);
    bubbleSort(9, arr);
    printArray(9, arr);
}

void bubbleSort(int n, int arr[])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int n, int arr[])
{
    for(int i = 0; i < n; i++)
    {
        int minIdx = i;
        //Iterate through every element from i+1th postion and find the smallest int's position
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

void insertionSort(int n, int arr[])
{
   for (i = 1; i < n; i++){
      temp = arr[i];
      j = i - 1;
      while ((temp < arr[j]) && (j >= 0)) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int logicalSize, int array[]) 
{
    printf("[");
    for (int i = 0; i < logicalSize; i++) {
        printf("%d", array[i]);
        if (i < logicalSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}