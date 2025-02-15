#include <stdio.h>
int main()
{
  float a, b, c, d, e;

  printf("Enter 3 numbers: ");
  scanf("%f%f%f", &a, &b, &c);
  d = a + b + c;
  e = (a + b + c) / 3;
  printf("SUM is: %f\nAVERAGE is: %f\n", d, e);

  return 0;
}