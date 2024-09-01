#include <stdio.h>
int main()
{
  char ch;
  printf("Enter the character: ");
  scanf("%c", &ch);

  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
  {
    if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch - 'A' + 'a';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
      ch = ch - 'a' + 'A';
    }
  }
  else
  {
    printf("%c is not an alphabet character\n");
  }
  printf("After changing case the character is %c", ch);

  return 0;
}