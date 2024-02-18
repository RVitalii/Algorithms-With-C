#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int* values;
    size_t length;
} Array;

void print_array(int* arr, size_t len) 
{
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

Array* get_diag_sums(int matrix[][3]) 
{
    Array* sums = (Array*)malloc(sizeof(Array));
    sums->length = 2;
    sums->values = (int*)malloc(sizeof(int) * sums->length);

    for (size_t i = 0; i < sums->length; i++) {
        sums->values[i] = 0;
    }

    for (size_t i = 0; i < 3; i++) {
        sums->values[0] += matrix[i][i];
        sums->values[1] += matrix[i][2 - i];
    }

    return sums;
}

Array* get_row_sums(int matrix[][3]) 
{
    Array* sums = (Array*)malloc(sizeof(Array));
    sums->length = 3;
    sums->values = (int*)malloc(sizeof(int) * sums->length);
    
    for (size_t i = 0; i < sums->length; i++) {
        sums->values[i] = 0;
    }

    for (size_t i = 0; i < sums->length; i++)
        for (size_t j = 0; j < sums->length; j++) {
            sums->values[i] += matrix[i][j];
        }

    return sums;
}

Array* get_col_sums(int matrix[][3]) 
{
    Array* sums = (Array*)malloc(sizeof(Array));
    sums->length = 3;
    sums->values = (int*)malloc(sizeof(int) * sums->length);

    for (size_t i = 0; i < sums->length; i++) {
        sums->values[i] = 0;
    }

    for (size_t i = 0; i < sums->length; i++)
        for (size_t j = 0; j < sums->length; j++) {
            sums->values[j] += matrix[i][j];
        }

    return sums;
}

int main() 
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Array* diag_sums = get_diag_sums(matrix);
    Array* row_sums = get_row_sums(matrix);
    Array* col_sums = get_col_sums(matrix);

    printf("Diagonal Sums: ");
    print_array(diag_sums->values, diag_sums->length);

    printf("Row Sums: ");
    print_array(row_sums->values, row_sums->length);
    
    printf("Column Sums: ");
    print_array(col_sums->values, col_sums->length);

    free(diag_sums->values);
    free(diag_sums);

    free(row_sums->values);
    free(row_sums);
    
    free(col_sums->values);
    free(col_sums);

    return 0;
}



