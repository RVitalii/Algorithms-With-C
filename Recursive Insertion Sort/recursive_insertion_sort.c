#include <stdio.h>

void printArray(int* arr, int len)
{
    int i = -1;
    while(++i < len)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void recursiveInsertionSort(int* arr, int pos, int len)
{
    int i = pos;
    while(i > 0 && arr[i] < arr[i-1])
    {
        swap(arr, i, i-1);
        --i;
    }
    if(pos < len-1) 
        recursiveInsertionSort(arr, ++pos, len);
}

int main()
{   
    int arr[5] = {3, 1, 8, 0, -3};
    recursiveInsertionSort(arr, 0, 5);
    printArray(arr, 5);
    return 0;
}