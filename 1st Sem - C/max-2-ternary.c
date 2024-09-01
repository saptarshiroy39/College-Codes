#include <stdio.h>
int main()
{
  int a, b, c;
  printf("Enter 2 numbers: ");
  scanf("%d%d", &a, &b);

  c = (a > b) ? a : b;
  printf("The MAXIMUM No. is : %d", c);

  return 0;
}