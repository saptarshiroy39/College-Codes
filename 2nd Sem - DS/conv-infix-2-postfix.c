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

//  Fubncion to get the precedence of an oprator
int getPrecedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
  int i, j;
  char stack[SIZE];
  int top = -1;
  for (i = 0, j = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] == ' ')
    {
      continue;
    }

    else if (isalnum(infix[i]))
    {
      postfix[j++] = infix[i];
    }

    else if (infix[i] == '(')
    {
      stack[++top] = infix[i];
    }

    else if (infix[i] == ')')
    {
      while (top != -1 && stack[top] != '(')
      {
        postfix[j++] = stack[top--];
      }
      top--; // Pop '('
    }

    else if (isOperator(infix[i]))
    {
      while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i]))
      {
        postfix[j++] = stack[top--];
      }
      stack[++top] = infix[i];
    }
  }
  while (top != -1)
  {
    postfix[j++] = stack[top--];
  }
  postfix[j] = '\0'; // Null terminate the expression
}

int main()
{
  char infix[SIZE];
  char postfix[SIZE];
  printf("Enter infix expression: ");
  fgets(infix, SIZE, stdin);
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}