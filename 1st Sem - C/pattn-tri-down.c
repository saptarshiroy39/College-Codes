#include <stdio.h>
int main()
{
  int i, j, row;
  printf("row: ");
  scanf("%d", &row);
  for (i = row; i >= 1; --i)
  {
    for (j = 1; j <= i; ++j)
    {
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}

/*
#include <stdio.h>
int main()
{
  int i, j, row;
  printf("row: ");
  scanf("%d", &row);
  for (i = row; i >= 1; --i)
  {
    for (j = 1; j <= i; ++j)
    {
      printf("%d ",j);
    }
    printf("\n");
  }
  return 0;
}

#include <stdio.h>
int main()
{
  int i, j, row;
  printf("row: ");
  scanf("%d", &row);
  for (i = row ; i >= 1; --i)
  {
    for (j = 'A'; j <= 'A' + i; ++j)
    {
      printf("%c ",j);
    }
    printf("\n");
  }
  return 0;
}
*/