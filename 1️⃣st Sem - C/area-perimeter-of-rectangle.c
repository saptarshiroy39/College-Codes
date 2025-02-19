#include <stdio.h>

int main()
{
  float a, b, c, d;

  printf("Enter lenght & bredth: ");
  scanf("%f%f", &a, &b);

  c = a * b;
  d = 2 * (a + b);
  
  printf("AREA is: %f\nPERIMETER is: %f\n", c, d);

  return 0;
}