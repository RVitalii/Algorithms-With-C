#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) do { \
    int temp = x; \
    x = y; \
    y = temp; \
} while (0)

int partition(int* arr, int start, int end)
{
    int pivot = arr[end];
    int pos = start - 1;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            pos++;
            SWAP(arr[pos], arr[i]);
        }
    }
    SWAP(arr[pos+1], arr[end]);
    return pos + 1;
}

int randomized_partition(int* arr, int start, int end)
{
    int pos = start + rand() % (end - start + 1);
    SWAP(arr[end], arr[pos]);
    return partition(arr, start, end);
}

int recursive_randomized_select(int* arr, int start, int end, int pos)
{
    if (start == end) {
        return arr[start];
    }
    int pivot = randomized_partition(arr, start, end);
    int distance = pivot - start;
    if (pos == distance) {
        return arr[pivot];
    } else if (pos < distance) {
        return recursive_randomized_select(arr, start, pivot-1, pos);
    } else {
        return recursive_randomized_select(arr, pivot+1, end, pos-distance-1);
    }
}

int iterative_randomized_select(int* arr, int start, int end, int pos)
{
    int pivot;
    int distance;
    while (start != end) {
        pivot = randomized_partition(arr, start, end);
        distance = pivot - start;
        if (pos == distance) {
            return arr[pivot];
        } else if (pos < distance) {
            end = pivot -1;
        } else {
            pos = pos-distance-1;
            start = pivot + 1;
        }
    }
    if (pos == 0) {
        return arr[start];
    }
}

int main()
{
    int arr[] = {10, 6, 8, 1, 2, 5, 4, 7, 3, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int recursive_result = recursive_randomized_select(arr, 0, n-1, k-1);
    int iterative_result = iterative_randomized_select(arr, 0, n-1, k-1);

    printf("RECURSIVE VERSION\n");
    printf("The %dth smallest element is: %d\n", k, recursive_result);
    printf("ITERATIVE VERSION\n");
    printf("The %dth smallest element is: %d\n", k, iterative_result);
    
    return 0;
}