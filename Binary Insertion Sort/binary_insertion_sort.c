#include <stdio.h>

void printArray(int* arr, int len)
{
    int i = -1;
    while(++i < len)
        printf("%d ", arr[i]);
    printf("\n");
}

int binarySearch(int* sorted_arr, int x, int pos1, int pos2)
{
    if(pos1 >= pos2)
        return (x > sorted_arr[pos1]) ? (pos1 + 1) : pos1;
    
    int mid = (pos1 + pos2) / 2;
    if(sorted_arr[mid] == x)
        return mid+1;
    else
        if(sorted_arr[mid] > x)
            binarySearch(sorted_arr, x, pos1, mid - 1);
        else 
            binarySearch(sorted_arr, x, mid + 1, pos2);
}

void insertLastElement(int* arr, int pos_to, int end)
{
    int temp = arr[end];
    for(int i = end; i > pos_to; --i)
        arr[i] = arr[i-1];
    arr[pos_to] = temp;
}

void binaryInsertionSort(int* arr, int len)
{
    for(int i = 0; i < len; ++i)
    {
        int pos = binarySearch(arr, arr[i], 0, i);
        insertLastElement(arr, pos, i);
    }
}

int main()
{
    int arr[5] = {3, 1, 8, 0, -3};
    binaryInsertionSort(arr, 5);
    printArray(arr, 5);

    return 0;
}