#include <stdio.h>
int main()
{
  int num, i;
  unsigned long long int fact = 1;
  printf("Enter a Number: ");
  scanf("%d", &num);
  if (num < 0)
  {
    printf("Error! Enter a Positive Number.");
  }
  else
  {
    for (i = 1; i <= num; ++i)
    {
      fact = fact * i;
    }
    printf("%d! = %llu", num, fact);
  }
  return 0;
}