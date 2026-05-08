#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if(rear == NULL)
    {
        front = rear = newNode;
    }

    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

// Dequeue operation
void dequeue()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }

    else
    {
        temp = front;

        printf("%d deleted\n", front->data);

        front = front->next;

        // If queue becomes empty
        if(front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

// Display queue
void display()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }

    else
    {
        temp = front;

        printf("Queue Elements:\n");

        while(temp != NULL)
        {
            printf("%d ", temp->data);

            temp = temp->next;
        }

        printf("\n");
    }
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}
