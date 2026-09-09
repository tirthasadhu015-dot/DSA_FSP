//werite a c program of check palindrome using queue.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return value;
}

int isPalindrome(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        enqueue(arr[i]);
    }

    if (isPalindrome(arr, size))
    {
        printf("The array is a palindrome.\n");
    }
    else
    {
        printf("The array is not a palindrome.\n");
    }

    return 0;
}
