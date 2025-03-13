#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void BitonicMerge(int arr[], int low, int count, bool ascending)
{
  if (count > 1)
  {
    int mid = count / 2;
    for (int i = low; i < low + mid; i++)
    {
      if ((arr[i] > arr[i + mid]) == ascending)
      {
        Swap(arr[i], arr[i + mid]);
      }
    }
    BitonicMerge(arr, low, mid, ascending);
    BitonicMerge(arr, low + mid, mid, ascending);
  }
}

void BitonicSort(int arr[], int low, int count, bool ascending)
{
  if (count > 1)
  {
    int mid = count / 2;
    BitonicSort(arr, low, mid, true);
    BitonicSort(arr, low + mid, mid, false);
    BitonicMerge(arr, low, count, ascending);
  }
}

int main()
{
  int n;
  cout << "Enter number of elements (must be 2^x): ";
  cin >> n;
  int arr[n];

  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  BitonicSort(arr, 0, n, true);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}