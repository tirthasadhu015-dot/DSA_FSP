//convert decimal number to binary in C using stack.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top = -1;
int stack[MAX];

void push(int c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main()
{
    int decimal, remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while (decimal != 0)
    {
        remainder = decimal % 2;
        push(remainder);
        decimal /= 2;
    }

    printf("Binary equivalent: ");
    while (top != -1)
    {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
