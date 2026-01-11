#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

// Function to check if the given chrarcter is an operator
int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix expression to infix expression
void postfixToInfix(char postfix[], char infix[])
{
  int j;
  char stack[SIZE][SIZE];
  int top = -1;

  for (j = 0; postfix[j] != '\0'; j++)
  {
    if (isalnum(postfix[j]))
    {
      sprintf(stack[++top], "%c", postfix[j]);
    }
    
    else if (isOperator(postfix[j]))
    {
      char op2[SIZE], op1[SIZE];
      strcpy(op2, stack[top--]);
      strcpy(op1, stack[top--]);
      sprintf(stack[++top], "(%s%c%s)", op1, postfix[j], op2);
    }
  }
  strcpy(infix, stack[top]);
}

int main()
{
  char postfix[SIZE];
  char infix[SIZE];
  
  printf("Enter postfix expression: ");
  fgets(postfix, SIZE, stdin);
  postfixToInfix(postfix, infix);
  printf("Infix expression: %s\n", infix);

  return 0;
}
