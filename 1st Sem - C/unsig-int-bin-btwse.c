#include <stdio.h>
int main()
{
  unsigned int num;
  unsigned int mask = 32768;
  printf("Enter the DECIMAL number: ");
  scanf("%u", &num);
  while (mask > 0)
  {
    if ((num & mask) == 0)
    {
      printf("0");
    }
    else
    {
      printf("1");
    }
    mask = mask >> 1;
  }
  printf(" is the BINARY value");
  return 0;
}