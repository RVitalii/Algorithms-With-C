#include <stdio.h>
#include <stdlib.h>


int randomSearch(int *arr, int len, int x)
{
    int rand_pos;
    int count = 0;
    int* visited = (int *)malloc(len*sizeof(int));
    do {
        rand_pos = rand() % len;
        if(visited[rand_pos] != 1) {
            visited[rand_pos] = 1;
            count++;
        }
    } while (arr[rand_pos] != x && count < len);
    free(visited);
    return count <= len ? rand_pos : -1;
}


void fillRandomInt(int* arr, int len, int max)
{
    for(int i=0; i<len; i++)
        arr[i] = rand() % max;
}


void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int n, max_val, x;
    printf("~~Starting Random Search~~\n");
    printf("Generate random integer sequence (length, max_val): ");
    scanf("%d", &n);
    scanf("%d", &max_val);
    int* arr = (int*) malloc(n * sizeof(int));
    fillRandomInt(arr, n, max_val);
    printArray(arr, n);
    printf("Find: ");
    scanf("%d", &x);
    int pos = randomSearch(arr, n, x);
    if(pos != -1)
        printf("%d is located at %d.\n", x, pos);
    else
        printf("%d not found!\n", x);
    return 0;
}