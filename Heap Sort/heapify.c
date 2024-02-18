#include<stdio.h>

void printArray(int array[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * (i + 1);
}

void maxHeapify(int array[], int heap_size, int i)
{
    int largest;
    int left_node = left(i);
    int right_node = right(i);

    if (left_node <= heap_size - 1 && array[left_node] > array[i])
        largest = left_node;
    else
        largest = i;

    if(right_node <= heap_size - 1 && array[right_node] > array[largest])
        largest = right_node;
    
    if(largest != i) 
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        maxHeapify(array, heap_size, largest);
    }
}

static void minHeapify(int array[], int heap_size, int i)
{
    int smallest;
    int left_node = left(i);
    int right_node = right(i);

    if (left_node <= heap_size - 1 && array[left_node] < array[i])
        smallest = left_node;
    else
        smallest = i;

    if(right_node <= heap_size - 1 && array[right_node] < array[smallest])
        smallest = right_node;
    
    if(smallest != i) 
    {
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;

        minHeapify(array, heap_size, smallest);
    }
}

static int main()
{
    int test1[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n1 = sizeof(test1) / sizeof(test1[0]);

    printf("INPUT 1: ");
    printArray(test1, n1);

    printf("MAX_HEAPIFY OUTPUT: ");
    maxHeapify(test1, n1, 1);
    printArray(test1, n1);

    int test2[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    int n2 = sizeof(test2) / sizeof(test2[0]);

    printf("INPUT 2: ");
    printArray(test2, n2);

    printf("MIN_HEAPIFY OUTPUT: ");
    minHeapify(test2, n2, 0);
    printArray(test2, n2);

    return 0;
}