#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    for (int j = i - 1; j >= 0; j--)
    {
      if (key < arr[j])
      {
        arr[j + 1] = arr[j];
        arr[j] = key;
      }
    }
  }
}

int main()
{
  int size, n;
  cout << "Enter size of Array : ";
  cin >> size;

  int arr[size];

  for (int i = 0; i < size; i++)
  {
    cout << "Element at " << i << ": ";
    cin >> arr[i];
  }

  insertionSort(arr, size);

  cout << "Sorted array: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}