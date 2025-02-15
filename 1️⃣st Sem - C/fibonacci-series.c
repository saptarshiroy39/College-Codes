#include <stdio.h>
int main()
{
  int a = 0, b = 1, c, i, number;
  printf("Enter the number of elements: ");
  scanf("%d", &number);
  printf("Fibonacci series of %d elements:\n", number);
  printf("%d %d", a, b);
  for (i = 2; i < number; ++i)
  {
    c = a + b;
    a = b;
    b = c;
    printf(" %d", c);
  }
  return 0;
}