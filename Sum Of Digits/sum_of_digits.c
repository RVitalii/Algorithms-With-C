#include <stdio.h>

int main()
{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);

    int sum = 0;
    while(n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    printf("Here is a sum of digits: %d\n", sum);

    return 0;
}
