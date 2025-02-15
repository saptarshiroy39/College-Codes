#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}

int partition(int array[], int low, int high)
{

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

int main()
{
  int i, size;

  cout << "Write the size of array : ";
  cin >> size;

  int arr[size];
  cout << "Enter Elements: ";
  for (i = 0; i < size; i++)
  {
    cin >> arr[i];
  }


  quickSort(arr, 0, size - 1);

  printf("Sorted array : ");
  for (int i = 0; i < size; ++i)
  {
    cout << arr[i] << " ";
  }

  return 0;
}