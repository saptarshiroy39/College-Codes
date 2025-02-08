#include <stdio.h>
int main()
{
  int n, a = 0;
  printf("Enter the number : ");
  scanf("%d", &n);
  if (n == 0 || n == 1)
  {
    a = 1;
  }
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      a = 1;
    }
  }
  if (a == 0)
  {
    printf("%d is a prime number", n);
  }
  else if (a == 1)
  {
    printf("%d is not a prime number", n);
  }
  return 0;
}