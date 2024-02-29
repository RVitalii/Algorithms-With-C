#include <stdio.h>

void print_array(int arr[], size_t len) {
    for (int i = 0; i < (len - 1); i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[len - 1]);
}

void counting_sort(int A[], size_t A_len, int B[], size_t B_len, size_t k) {
    int C[k + 1];
    for (size_t i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (size_t i = 0; i < A_len; i++) {
        C[A[i]] = C[A[i]] + 1;
    }

    for (size_t i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (size_t i = A_len - 1; i < A_len; i--) {
        B[C[A[i]] - 1] = A[i]; 
        C[A[i]] = C[A[i]] - 1;
    }
}

int main() {
    int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
    size_t A_len = sizeof(A) / sizeof(A[0]);
    int B[A_len];
    size_t B_len = sizeof(B) / sizeof(B[0]);
    size_t k = 5;

    printf("Original array: ");
    print_array(A, A_len);

    counting_sort(A, A_len, B, B_len, k);

    printf("Sorted array: ");
    print_array(B, B_len);

    return 0;
}
