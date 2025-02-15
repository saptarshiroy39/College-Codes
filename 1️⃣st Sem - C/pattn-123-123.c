#include <stdio.h>
int main()
{
  int i, j, rows;
  printf("Enter the numbers of ROWS: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; ++i)
  {
    for (j = 1; j <= rows; ++j)
    {
      printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}