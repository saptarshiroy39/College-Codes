#include <iostream>
using namespace std;

void OddEvenSort(int arr[], int n)
{
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;

    // Odd indexed pass
    for (int i = 1; i < n - 1; i += 2)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
        sorted = false;
      }
    }

    // Even indexed pass
    for (int i = 0; i < n - 1; i += 2)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
        sorted = false;
      }
    }
  }
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  int arr[n];

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  OddEvenSort(arr, n);

  cout << "Sorted array: ";

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}