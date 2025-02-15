#include <stdio.h>
int main()
{
  char ch;
  printf("Enter an alphabet character: ");
  scanf("%c", &ch);

  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
  {
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      printf("%c is VOWEL", ch);
    }
    else
    {
      printf("%c is CONSONANT", ch);
    }
  }

  else
  {
    printf("Input is not an alphabet character\n");
  }

  return 0;
}