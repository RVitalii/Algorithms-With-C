#include<stdio.h>

void printArray(int array[], int n);
int left(int i);
int right(int i);
void maxHeapify(int array[], int heap_size, int i);

void buildMaxHeap(int array[], int n)
{
    int heap_size = n; 

    for(int i = (n-1)/ 2; i >= 0; i--)
        maxHeapify(array, heap_size, i);
}


void heapSort(int array[], int n)
{
    buildMaxHeap(array, n);
    
    int heap_size = n;
    for(int i = n-1; i >= 1; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heap_size = heap_size - 1;
        maxHeapify(array, heap_size, 0);
    }
}

int main()
{
    int test1[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n1 = sizeof(test1) / sizeof(test1[0]);

    printf("INPUT_1: ");
    printArray(test1, n1);

    printf("MAX_HEAP: ");
    buildMaxHeap(test1, n1);
    printArray(test1, n1);

    printf("HEAP_SORT OUTPUT: ");
    heapSort(test1, n1);
    printArray(test1, n1);
}