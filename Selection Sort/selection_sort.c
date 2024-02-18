#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int len)
{
    int i = 0;
    while((i+1) != len)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("%d\n", arr[i]);
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void selection_sort(int* arr, int n)
{  
    int start = 0;
    while(start < n-1)
    {  
        for(int i = start; i < n; ++i)
            if(arr[i] < arr[start])
                swap(arr, i, start);
        ++start;
    }
}

int main() 
{
    int arr[5] = {3, 1, 8, 0, -3};
    selection_sort(arr, 5);
    printArray(arr, 5);
    return 0;
}