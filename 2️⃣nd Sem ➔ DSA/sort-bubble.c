#include <stdio.h>

void bubbleSort(int size, int array[size])
{
  int count = 0;
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      count++; // Increment step count for each comparison
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  printf("Step count: %d\n", count);
}

int main()
{
  int size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter %d elements: ", size);
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

  bubbleSort(size, array);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}