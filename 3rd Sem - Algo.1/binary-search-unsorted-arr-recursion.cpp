#include <iostream>
using namespace std;

int bubbleSort(int arr[], int size, int copy[])
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        int cpy = copy[j];
        copy[j] = copy[j + 1];
        copy[j + 1] = cpy;
      }
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
  int copy[size];

  cout << "Enter " << size << " Elements : ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
    copy[i] = i;
  }

  bubbleSort(arr, size, copy);

  cout << "Enter Element to search : ";
  cin >> n;

  int result = binarySearch(arr, 0, size - 1, n);

  if (result != -1)
  {
    cout << "Element found @ index " << copy[result] << " of original Array"<<endl;
  }

  else
  {
    cout << "Element not found" << endl;
  }
  
  return 0;
}