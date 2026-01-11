#include <stdio.h>
int main()
{
  int a, b, temp;

  printf("Enter 2 numbers: ");
  scanf("%d%d", &a, &b);
  temp = a;
  a = b;
  b = temp;
  printf("After swapping the numbers are: %d %d", a, b);

  return 0;
}