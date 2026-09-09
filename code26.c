// Implementation of Queue using Array
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value)
{
    if (rear == MAX - 1)
    {   printf("Queue Overflow\n");  return;   }
    if (front == -1)   front = 0;
       queue[++rear] = value;
    printf("%d inserted into queue\n", value);
}
void dequeue()
{
    if (front == -1)
    {  printf("Queue Underflow\n");return;    }
    printf("%d deleted from queue\n", queue[front]);
    if (front == rear)
    { front = -1; rear = -1;
    }
    else
    {front++;}
}
void peek()
{
    if (front == -1)
           printf("Queue is empty\n");  
    else
    printf("Front element = %d\n", queue[front]);
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n--- QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}