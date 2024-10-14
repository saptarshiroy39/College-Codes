#include <stdio.h>

int reverse(int x)
{
  int rev = 0;

  while (x != 0)
  {
    rev = rev * 10 + x % 10;
    x /= 10;
  }

  return rev;
}

int main()
{
  int num;
  printf("Enter Number : ");
  scanf("%d", &num);

  int rev_num = reverse(num);
  printf("Reversed Number: %d", rev_num);

  return 0;
}
