// 22-08-2024

#include <iostream>
using namespace std;

int binarySearch(int A[], int size, int target)
{
  int left = 0;
  int right = size - 1;
  while (left <= right)
  {
    int mid = (right + left) / 2;
    if (A[mid] == target)
    {
      return mid;
    }
    else if (A[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int size, n;
  cout << "Enter size of Array : ";
  cin >> size;

  int A[size];

  cout << "Enter Elements : ";
  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }

  cout << "Enter Element to search : ";
  cin >> n;
  int result = binarySearch(A, size, n);
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