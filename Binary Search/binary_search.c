#include <stdio.h>

int binarySearch(int x, int* sorted_arr, int pos, int len)
{
    if (pos > len)
        return -1;

    int mid = (len + pos) / 2;
    if(sorted_arr[mid] == x)
        return mid;
    else 
        if(sorted_arr[mid] > x)
            binarySearch(x, sorted_arr, pos, mid-1);
        else
            binarySearch(x, sorted_arr, mid+1, len);
}

int main()
{
    int sorted_arr[5] = {10, 18, 20, 25, 100};
    printf("%d\n", binarySearch(1, sorted_arr, 0, 5));
    return 0;
}