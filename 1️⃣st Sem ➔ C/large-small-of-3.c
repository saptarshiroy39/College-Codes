#include <stdio.h>

int main()
{
  int a, b, c;
  printf("Enter 3 different numbers: ");
  scanf("%d%d%d", &a, &b, &c);

  if (a > b && a > c)
  {
    printf("%d is LARGEST\n", a);
  }
  else if (a < b && a < c)
  {
    printf("%d is SMALLEST\n", a);
  }
  if (b > a && b > c)
  {
    printf("%d is LARGEST\n", b);
  }
  else if (b < a && b < c)
  {
    printf("%d is SMALLEST\n", b);
  }
  if (c > b && c > a)
  {
    printf("%d is LARGEST\n", c);
  }
  else if (c < b && c < a)
  {
    printf("%d is SMALLEST\n", c);
  }

  return 0;
}