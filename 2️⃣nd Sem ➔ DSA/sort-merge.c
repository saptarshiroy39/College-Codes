#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays L[] R[]
  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr[left..right]
  int i = 0;    // Initial index of 1st subarray
  int j = 0;    // Initial index of 2nd subarray
  int k = left; // Initial index of merged subarray
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

  // Copy the remaining elements of L[], if any
  while (i < n1)
  {
    arr[k++] = L[i++];
  }

  while (j < n2)
  {
    arr[k++] = R[j++];
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

  printf("Enter Elements : ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, size - 1);

  printf("Sorted array is: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}