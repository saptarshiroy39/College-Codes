#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays L[] R[]
  for (i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr[left..right]
  i = 0;    // Initial index of 1st subarray
  j = 0;    // Initial index of 2nd subarray
  k = left; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }

  // Copy the remaining elements ofL[], if any
  while (i < n1)
  {
    arr[k++] = L[i++];
  }
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    // Same as (left+right)/2, but avoids overflow for large left and right
    int mid = left + (right - left) / 2;

    // sort 1st & 2nd halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main()
{
  int size;
  printf("Write the length of array: ");
  scanf("%d", &size);
  
  int arr[size];
  for (int i = 0; i < size; i++)
  {
    printf("%d = ", i);
    scanf("%d", &arr[i]);
  }

  printf("Given array is: \n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  mergeSort(arr, 0, size - 1);

  printf("\n");

  printf("Sorted array is: \n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}