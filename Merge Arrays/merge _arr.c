#include<stdio.h>

void merge(int leftArr[], int rightArr[], int mergedArr[], int nLeft, int nRight)
{
    int n = nLeft + nRight;
    
    for(int i = 0; i < nLeft; i++)
        mergedArr[i] = leftArr[i];

    for(int i = nLeft; i < n; i++)
    {
        int iRight = i - nLeft;
        mergedArr[i] = rightArr[iRight];
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8,9};
    int nLeft = 4;
    int nRight = 5;
    int n = 9;

    int mergedArr[n];
    merge(arr1, arr2, mergedArr, 4, 5);
    printArray(mergedArr, 9);
    
    return 0;
}