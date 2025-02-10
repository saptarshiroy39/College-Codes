#include <stdio.h>
#include <string.h>
int main()
{
  char str[999];
  int vowels = 0, consonant = 0, number = 0, space = 0;
  printf("Enter a line of string: ");
  gets(str);
  int strlength = strlen(str);

  for (int i = 0; i < strlength; i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
    {
      vowels++;
    }

    else if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
    {
      number++;
    }

    else if (str[i] == ' ')
    {
      space++;
    }

    else
    {
      consonant++;
    }
  }

  printf("Vowel Count: %d\n", vowels);
  printf("Consonant Count: %d\n", consonant);
  printf("Number Count: %d\n", number);
  printf("Space Count: %d\n", space);

  return 0;
}