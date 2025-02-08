#include <stdio.h>
int main()
{
  int num, rev = 0, rem, ori;
  printf("Enter a number: ");
  scanf("%d", &num);
  ori = num;
  while (num != 0)
  {
    rem = num % 10;
    rev = rev * 10 + rem;
    num = num / 10;
  }
  if (ori == rev)
  {
    printf("%d is PALINDROME.\n", ori);
  }
  else
  {
    printf("%d is NOT PALINDROME.\n", ori);
  }
  return 0;
}