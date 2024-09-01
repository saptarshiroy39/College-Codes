#include <stdio.h>

int main()
{
  float num1, num2;
  char operator;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Enter the second number: ");
  scanf("%f", &num2);

  switch (operator)
  {
  case '+':
    printf("The result is: %f\n", num1 + num2);
    break;

  case '-':
    printf("The result is: %f\n", num1 - num2);
    break;

  case '*':
    printf("The result is: %f\n", num1 * num2);
    break;

  case '/':
    if (num2 == 0)
    {
      printf("Error: Division by zero is not allowed.\n");
    }
    else
    {
      printf("The result is: %f\n", num1 / num2);
    }
    break;

  default:
    printf("Error: Invalid operator.\n");
    break;
  }

  return 0;
}