#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int c = 0;
// Declearing the variables for stack-
struct stack
{
  int a[SIZE]; // making array
  int top;     // pointer variable
};

typedef struct stack st;

// fuction for creating an EMPTY STACK
void ces(st *s)
{
  s->top = -1;
}

// function for overflow checking before PUSH
int isoverflow(st *s)
{
  return (s->top == SIZE - 1);
}

// function for underflow checking before POP
int isunderflow(st *s)
{
  return (s->top == -1);
}

// function for PUSH
void push(st *s, int element)
{
  if (isoverflow(s))
  {
    printf("Stack Overflow!\n");
  }
  else
  {
    s->top++;
    s->a[s->top] = element;
  }
  c++;
}

// function for POP
void pop(st *s)
{
  if (isunderflow(s))
  {
    printf("Stack Underflow!\n");
  }
  else
  {
    printf("popped element is %d\n", s->a[s->top]);
    s->top--;
  }
  c--;
}

// function for STACK PRINTING
void printstack(st *s)
{
  printf("Current stack : \n");
  for (int i = 0; i < c; i++)
  {
    printf("%d\n", s->a[i]);
    //printf("\n");
  }
}

// main function
int main()
{
  st *s = (st *)malloc(sizeof(st));
  int choice, element;

  while (1)
  {
    printf("1. CREATE a STACK\n");
    printf("2. PUSH\n");
    printf("3. POP\n");
    printf("4. DISPLAY stack\n");
    printf("5. EXIT\n");
    printf("\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
      ces(s);
      break;

    case 2:
      printf("Enter the element to push: ");
      scanf("%d", &element);
      push(s, element);
      printf("\n");
      break;

    case 3:
      pop(s);
      break;

    case 4:
      printstack(s);
      break;

    case 5:
      printf("Exiting...\n");
      return 0;

    default:
      printf("Invalid choice !\n");
    }
  }

  return 0;
}