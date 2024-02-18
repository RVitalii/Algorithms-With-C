#include<stdio.h>
#include <stdbool.h>

#define MAXSIZE 1000


int top = -1;        
double stack[MAXSIZE];


int isEmpty()
{ 
    return top == -1 ? true : false;
}


int isFull()
{
    return top == (MAXSIZE - 1) ? true : false;
}

void push(double value)
{
    if (isFull())
        printf("The stack is full.");
    else {
        top++;
        stack[top] = value;
    }
}


double pop()
{
    double out;
    if (isEmpty())
        printf("The stack is empty.");
    else {
        out = stack[top];
        top--;
    }
    return out;
}


void show()
{
    if (isEmpty())
        printf("The stack is empty.");
    else {
        for (int i = top; i >= 0; --i)
            printf("%.2lf\n", stack[i]);
    }
}


int getTopIndex()
{
    return top;
}

