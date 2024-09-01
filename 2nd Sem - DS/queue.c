#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure to represent a queue
struct queue
{
  int a[SIZE];
  int front;
  int rear;
};

typedef struct queue qu;

// Function to initialize a queue
void inq(qu *q)
{
  q->front = -1;
  q->rear = -1;
}

// Function to check if the queue is full
int isFull(qu *q)
{
  return (q->rear == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(qu *q)
{
  return (q->front == -1 && q->rear == -1);
}

// Function enqueue
void enqueue(qu *q, int value)
{
  if (isFull(q))
  {
    printf("Queue is full. Cannot enqueue.\n");
  }

  if (isEmpty(q))
  {
    q->front = 0;
  }

  q->rear++;
  q->a[q->rear] = value;
}

// Function dequeue
void dequeue(qu *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty. Cannot Dequeue\n");
  }

  if (q->front == q->rear)
  {
    q->front = -1;
    q->rear = -1;
  }

  else
  {
    q->front++;
  }

  printf("Dequeued item: %d\n", q->a[q->front]);
}

// Function to display the front element of the queue
int front(qu *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty.\n");
    return -1;
  }

  return q->a[q->front];
}

// Function to display the rear element of the queue
int rear(qu *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty.\n");
    return -1;
  }

  return q->a[q->rear];
}

// Function to display the elements of the queue
void printQueue(qu *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty.\n");
    return;
  }

  printf("Queue elements are: ");
  for (int i = q->front; i <= q->rear; i++)
  {
    printf("%d ", q->a[i]);
  }
  printf("\n");
}

// Main function
int main()
{
  qu *q = (qu *)malloc(sizeof(qu));

  int choice, value;
  while (1)
  {
    printf("1. CREATE a QUEUE\n");
    printf("2. ENQUEUE\n");
    printf("3. DEQUEUE\n");
    printf("4. FRONT element\n");
    printf("5. REAR element\n");
    printf("6. DISPLAY queue\n");
    printf("7. EXIT\n");
    printf("\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
      inq(q);
      break;

    case 2:
      printf("Enter value to enqueue: ");
      scanf("%d", &value);
      enqueue(q, value);
      printf("\n");
      break;

    case 3:
      dequeue(q);
      break;

    case 4:
      printf("Front element: %d\n", front(q));
      break;

    case 5:
      printf("Rear element: %d\n", rear(q));
      break;

    case 6:
      printQueue(q);
      break;

    case 7:
      printf("Exiting...\n");
      return 0;

    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}
