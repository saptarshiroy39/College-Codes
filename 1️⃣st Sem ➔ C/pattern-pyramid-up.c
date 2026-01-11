#include <stdio.h>
int main()
{
  int row, i, a, b;
  printf("Enter number of rows : ");
  scanf("%d", &row);

  for (i = 0; i <= row; i++)
  {
    for (a = 1; a <= row - i; a++)
    {
      printf(" ");
    }
    for (b = 1; b <= 2 * i - 1; b++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

/*

#include <stdio.h>

int main()
{
  int row, i, a, b;
  printf("Enter number of rows : ");
  scanf("%d", &row);

  for (i = 0; i <= row; i++)
  {
    for (a = 1; a <= row - i; a++)
    {
      printf(" ");
    }
    for (b = 1; b <= 2 * i - 1; b++)
    {
      printf("%d",b);
    }
    printf("\n");
  }

  return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
  int row, i, a, b;
  printf("Enter number of rows : ");
  scanf("%d", &row);

  for (i = 1; i <= row; i++)
  {
    for (a = 1; a <= row - i; a++)
    {
      printf(" ");
    }
    for (b = 'A'; b <= 'A' + 2 * i - 1; b++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
  int row, i, a, b;
  printf("Enter number of rows : ");
  scanf("%d", &row);
  
  for (i = 0; i <= row; i++)
  {
    for (a = 1; a <= row - i; a++)
    {
      printf(" ");
    }
    for (b = 'A'; b <= 'A' + 2 * i - 2; b++)
    {
      printf("%c", b);
    }
    printf("\n");
  }

  return 0;
}
  
*/