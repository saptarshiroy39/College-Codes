#include <stdio.h>

int main()
{
  float cel, feh, kel;

  printf("Enter the celcius value: ");
  scanf("%f", &cel);

  feh = ((9 * cel) + 160) / 5;
  printf("Fahrenheit value is: %f", feh);

  kel = cel + 273.15;
  printf("\nKelvin value is: %f", kel);

  return 0;
}