#include <stdio.h>

void array2D(int row, int column, int arr[row][column])
{

  printf("2D Array = \n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int row, column;
  printf("Write array size: ");
  scanf("%d%d", &row, &column);

  int arr[row][column];
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("[%d][%d]= ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  array2D(row, column, arr);

  return 0;
}