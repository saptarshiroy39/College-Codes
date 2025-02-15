#include <stdio.h>
int main()
{
  int a;
  printf("Enter the number: ");
  scanf("%d", &a);

  if (a % 2 == 0)
  {
    printf("%d is EVEN NUMBER", a);
  }
  else
  {
    printf("%d is ODD NUMBER", a);
  }

  return 0;
}