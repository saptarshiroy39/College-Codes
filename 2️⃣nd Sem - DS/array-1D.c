#include <stdio.h>
void array1D(int row, int arr[row])
{
  printf("1D Array = \n");
  for (int i = 0; i < row; i++)
  {
    printf("%d ", arr[i]);
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
  
  array1D(row, arr);

  return 0;
}