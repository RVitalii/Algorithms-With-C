#include<stdio.h>

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int L[], int R[], int l, int r)
{   
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < l && j < r)
        {
            if(L[i] < R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else 
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    
        while(i < l)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < r)
        {
            arr[k] = R[j];
            j++;
            k++;
        }  
}

void mergeSort(int arr[], int len)
{
    if(len > 1)
    {
        int mid = len / 2;
        int l = mid;
        int r = len - mid;

        int L[l];
        for(int i = 0; i < l; i++)
            L[i] = arr[i];

        int R[r];
        for(int i = l; i < len; i++)
            R[i - l] = arr[i];

        mergeSort(L, l);
        mergeSort(R, r);
        merge(arr, L, R, l, r);
    }
}

int main()
{
    int test[] = {2,8,0,3,4,10,-1};
    int n = sizeof(test) / sizeof(test[0]);

    mergeSort(test, n);
    printArray(test, n);
    
    return 0;
}