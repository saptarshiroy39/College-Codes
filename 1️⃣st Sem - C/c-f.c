#include <stdio.h>
int main()
{
  float a, b;

  printf("Enter the celcius value: ");
  scanf("%f", &a);
  b = ((9 * a) + 160) / 5;
  printf("Fahrenheit value is: %f", b);

  return 0;
}