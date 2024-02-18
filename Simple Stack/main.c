#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
    int option;
    double value;

    while (true)
    {
        printf("\n~~ STACK OPERATIONS ~~\n\n");
        printf("Main Menu");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Get Top Index\n5.Exit");
        printf("\n\nINPUT: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("Enter value: ");
            scanf("%lf", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Stack:\n");
            show();
            break;
        case 4:
            printf("Top index: %d\n", getTopIndex());
            break;
        case 5:
            exit(0);

        default:
            printf("\nERROR: Invalid option!");
        }
    }

    return 0;
}