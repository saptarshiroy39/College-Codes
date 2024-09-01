#include <stdio.h>

// Function to swap the position of two elements
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// To heapify a subtree rooted with node i
// Which is an index in arr[]
// n is size of heap
void heapify(int arr[], int size, int i)
{
  // Find largest among root,
  // left child and right child
  // Initialize largest as root
  int largest = i;
  // left=2*i+1
  int left = 2 * i + 1;
  // right=2*i+2
  int right = 2 * i + 2;
  // if left child is larger than root
  if (left < size && arr[left] > arr[largest])
    largest = left;
  // if right child is larger than largest
  // so far
  if (right < size && arr[right] > arr[largest])
    largest = right;
  // swap and continue heapifying
  // if root is not largest
  // if largest is  not root
  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    // Recursively heapify the affected
    // sub-tree
    heapify(arr, size, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int size)
{
  // Build max heap
  for (int i = size; i >= 0; i--)
  {
    heapify(arr, size, i);
  }
  // Heap sort
  for (int i = size - 1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]);
    // Heapify root element
    // to get highest element at
    // root again
    heapify(arr, i, 0);
  }
}

// Driver's code
int main()
{
  int i, size;
  printf("Enter the size of the array : ");
  scanf("%d", &size);

  int arr[size];

  for (i = 0; i < size; i++)
  {
    printf("Element at [%d] : ", i);
    scanf("%d", &arr[i]);
  }

  // Function call
  heapSort(arr, size);

  printf("Sorted array is \n");
  for (int i = 0; i < size; i++)
  {
    printf(" %d", arr[i]);
  }

  return 0;
}