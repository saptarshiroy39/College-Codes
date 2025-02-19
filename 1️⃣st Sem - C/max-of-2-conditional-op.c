#include <stdio.h>

int main()
{
  int a, b;
  printf("Enter 2 numbers: ");
  scanf("%d%d", &a, &b);

  if (a > b)
  {
    printf("%d is MAXIMUM", a);
  }
  else if (b > a)
  {
    printf("%d is MAXIMUM", b);
  }
  else if (b == a)
  {
    printf("2 numbers are same, USE DIFFERENT NUMBERS");
  }

  return 0;
}