#include <iostream>
using namespace std;

int bubbleSort(int arr[], int size)
{
  int swap;

  for (int i = 0; i < size - 1; i++)
  {
    swap = 0;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swap = 1;
      }
    }

    if (!swap)
    {
      break;
    }
  }
}

int binarySearch(int arr[], int low, int high, int key)
{

  if (high < low)
  {
    return -1;
  }
  else
  {
    int mid = (low + high) / 2;
    if (key == arr[mid])
    {
      return mid;
    }

    else if (key > arr[mid])
    {
      binarySearch(arr, mid + 1, high, key);
    }
    else
    {
      binarySearch(arr, low, mid - 1, key);
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

  bubbleSort(arr, size);

  cout << "Enter Element to search : ";
  cin >> n;

  int result = binarySearch(arr, 0, size - 1, n);

  if (result != -1)
  {
    cout << "Element found at index : " << result << endl;
  }

  else
  {
    cout << "Element not found" << endl;
  }
  return 0;
}