#include <stdio.h>

void selectionSort(int row, int column, int arr[row][column])
{

  int i, j, x, y, temp;

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      for (x = 0; x < row; x++)
      {
        for (y = 0; y < column; y++)
        {
          if (arr[i][j] < arr[x][y])
          {
            temp = arr[i][j];
            arr[i][j] = arr[x][y];
            arr[x][y] = temp;
          }
        }
      }
    }
  }
}

int main()
{

  int i, j, row, column;

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

  printf("Original Array = \n");

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf(" %d ", arr[i][j]);
    }
    printf("\n");
  }

  selectionSort(row, column, arr);

  printf("\nSorted Array: \n");

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < column; j++)
    {
      printf(" %d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}