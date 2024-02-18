#include <stdio.h>

int sum(int n);

int main() 
{
    int n, result;

    printf("Enter an integer: ");
    scanf("%d", &n);

    result = sum(n);
    
    printf("sum = %d\n", result);
    return 0;
}

int sum(int n)
{
    if(n == 0)
        return n;
    else
        return n + sum(n-1);
}