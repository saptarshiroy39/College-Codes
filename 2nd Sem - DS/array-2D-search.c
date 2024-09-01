#include <stdio.h>
int main()
{
  int row, column, n, a;
  int i, j;
  printf("Write array size: ");
  scanf("%d%d", &row, &column);
  int arr[row][column];

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf("[%d][%d]= ", i, j);
      scanf("%d", &arr[i][j]);
    }
    printf("\n");
  }

  printf("Enter element: ");
  scanf("%d", &n);

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      if (n == arr[i][j])
      {
        printf("Position of %d is:\nrow = %d\ncolumn = %d\n", n, i, j);
        a = 1;
      }
    }
  }

  if (a != 1)
    printf("NOT FOUND !");

  return 0;
}