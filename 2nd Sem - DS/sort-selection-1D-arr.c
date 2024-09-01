#include <stdio.h>
void selectionSort(int row, int arr[row])
{
  for (int i = 0; i < row; i++)
  {
    for (int x = 0; x < row; x++)
    {
      if (arr[i] < arr[x])
      {
        int temp = arr[i];
        arr[i] = arr[x];
        arr[x] = temp;
      }
    }
  }
}

int main()
{
  int row;
  printf("Write array size: ");
  scanf("%d", &row);

  int arr[row];
  for (int i = 0; i < row; i++)
  {
    printf("%d = ", i);
    scanf("%d", &arr[i]);
  }

  printf("Original Array: \n");
  for (int i = 0; i < row; i++)
  {
    printf(" %d ", arr[i]);
  }

  selectionSort(row, arr);

  printf("\nSorted Array: \n");
  for (int i = 0; i < row; i++)
  {
    printf(" %d ", arr[i]);
  }

  return 0;
}