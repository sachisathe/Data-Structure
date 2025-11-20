//Two Queues using single array

#include <stdio.h>
#define MAX 10

int queue[MAX];
int front1 = 0, rear1 = -1;
int front2 = MAX - 1, rear2 = MAX;

void enqueue1(int value) 
{
    if (rear1 + 1 == rear2) 
    {
        printf("Queue Overflow! No space for Queue 1.\n");
    } else 
    {
        queue[++rear1] = value;
        printf("%d inserted in Queue 1\n", value);
    }
}

void enqueue2(int value) 
{
    if (rear1 + 1 == rear2) 
    {
        printf("Queue Overflow! No space for Queue 2.\n");
    } else 
    {
        queue[--rear2] = value;
        printf("%d inserted in Queue 2\n", value);
    }
}

void dequeue1() 
{
    if (front1 > rear1) 
    {
        printf("Queue 1 is Empty.\n");
    } else 
    {
        printf("%d deleted from Queue 1\n", queue[front1++]);
    }
}

void dequeue2() 
{
    if (front2 < rear2) 
    {
        printf("Queue 2 is Empty.\n");
    } else 
    {
        printf("%d deleted from Queue 2\n", queue[front2--]);
    }
}

void display1() 
{
    if (front1 > rear1) 
    {
        printf("Queue 1 is empty.\n");
    } else 
    {
        printf("Queue 1 elements: ");
        for (int i = front1; i <= rear1; i++) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void display2() 
{
    if (front2 < rear2) 
    {
        printf("Queue 2 is empty.\n");
    } else 
    {
        printf("Queue 2 elements: ");
        for (int i = front2; i >= rear2; i--) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice, value;

    while (1) 
    {
        printf("\n---- Two Queue Menu ----\n");
        printf("1. Enqueue in Queue 1\n");
        printf("2. Enqueue in Queue 2\n");
        printf("3. Dequeue from Queue 1\n");
        printf("4. Dequeue from Queue 2\n");
        printf("5. Display Queue 1\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter value to insert in Queue 1: ");
            scanf("%d", &value);
            enqueue1(value);
            break;
        case 2:
            printf("Enter value to insert in Queue 2: ");
            scanf("%d", &value);
            enqueue2(value);
            break;
        case 3:
            dequeue1();
            break;
        case 4:
            dequeue2();
            break;
        case 5:
            display1();
            break;
        case 6:
            display2();
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}