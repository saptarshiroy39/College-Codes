#include <stdio.h>

void bubbleSort(int size, int array[size], int *count)
{
  int swap;

  for (int i = 0; i < size - 1; i++)
  {
    swap = 0; // Flag to check if any swaps occurred in the inner loop
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        // swap the elements
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swap = 1; // Set flag if a swap happened
        (*count)++;  // Increment step counter
      }
    }

    // If no swaps occurred in the inner loop, the array is already sorted
    if (!swap)
    {
      break;
    }
  }
}

int main()
{
  int size, count = 0;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter %d elements:\n", size);
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("Original array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  bubbleSort(size, array, &count);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Total steps taken: %d\n", count);

  return 0;
}