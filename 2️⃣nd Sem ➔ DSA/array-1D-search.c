#include <stdio.h>

int main()
{
  int row, n, a;
  printf("Write array size: ");
  scanf("%d", &row);
  int arr[row];
  printf("Write array:\n");

  for (int i = 0; i < row; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Enter element: ");
  scanf("%d", &n);

  for (int i = 0; i < row; i++)
  {
    if (arr[i] == n)
    {
      printf("Position of %d is %d\n", n, i + 1);
      a = 1;
    }
  }

  if (a != 1)
    printf("NOT FOUND !");

  return 0;
}