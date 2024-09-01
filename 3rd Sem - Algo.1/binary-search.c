//22-08-2024

#include <stdio.h>

int binarySearch(int A[], int size, int target)
{
  int left = 0;
  int right = size - 1;
  while (left <= right)
  {
    int mid = (right + left) / 2;
    if (A[mid] == target)
    {
      return mid;
    }
    else if (A[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int size, n;
  printf("Enter size of Array : ");
  scanf("%d", &size);

  int A[size];

  for (int i = 0; i < size; i++)
  {
    printf("Element at [%d] : ", i);
    scanf("%d", &A[i]);
  }

  printf("Enter Element to search : ");
  scanf("%d", &n);
  int result = binarySearch(A, size, n);
  if (result != -1)
  {
    printf("Element found at index : %d\n", result);
  }

  else
  {
    printf("Element not found\n");
  }
  return 0;
}