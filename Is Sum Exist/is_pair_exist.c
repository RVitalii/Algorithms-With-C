#include <stdio.h>
#include <stdbool.h>

void printArray(int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int L[], int R[], int l, int r) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < l && j < r) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < l) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < r) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int len) {
    if (len <= 1)
        return;

    int mid = len / 2;
    int l = mid;
    int r = len - mid;

    int L[l];
    for (int i = 0; i < l; ++i)
        L[i] = arr[i];

    int R[r];
    for (int i = l; i < len; ++i)
        R[i - l] = arr[i];

    mergeSort(L, l);
    mergeSort(R, r);
    merge(arr, L, R, l, r);
}

int binarySearch(int x, int* sorted_arr, int pos, int len) {
    if (pos > len)
        return -1;

    int mid = (len + pos) / 2;
    if (sorted_arr[mid] == x)
        return mid;
    else if (sorted_arr[mid] > x)
        return binarySearch(x, sorted_arr, pos, mid - 1);
    else
        return binarySearch(x, sorted_arr, mid + 1, len);
}

int main() {
    int x = 10;
    int S[] = {2, 8, 0, 3, 4, 10, -1};
    int len = sizeof(S) / sizeof(S[0]);

    mergeSort(S, len);

    bool pairExists = false;
    for (int i = 0; i < len; ++i) {
        int s1 = x - S[i];
        if (binarySearch(s1, S, 0, len) != -1) {
            printf("Elements s1 = %d and s2 = %d exist such that s1 + s2 = %d.\n", s1, S[i], x);
            pairExists = true;
            break;
        }
    }

    if (!pairExists)
        printf("No elements s1 and s2 exist in S such that s1 + s2 = %d.\n", x);

    return 0;
}