#include <iostream>
using namespace std;

int findMax(int arr[], int start, int end)
{
  if (start == end)
  {
    return arr[start];
  }

  int mid = (start + end) / 2;
  int left = findMax(arr, start, mid);
  int right = findMax(arr, mid + 1, end);

  if (left > right)
  {
    return left;
  }
  else
  {
    return right;
  }
}

int findMin(int arr[], int start, int end)
{
  if (start == end)
  {
    return arr[start];
  }

  int mid = (start + end) / 2;
  int left = findMin(arr, start, mid);
  int right = findMin(arr, mid + 1, end);

  if (left < right)
  {
    return left;
  }
  else
  {
    return right;
  }
}

int main()
{
  int n;
  cout << "Size of List: ";
  cin >> n;

  int arr[n];

  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int max = findMax(arr, 0, n - 1);
  int min = findMin(arr, 0, n - 1);

  cout << "Maximum element: " << max << endl;
  cout << "Minimum element: " << min << endl;

  return 0;
}