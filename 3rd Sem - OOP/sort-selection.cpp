#include <iostream>
using namespace std;

void Sort(int row, int arr[])
{
  for (int i = 0; i < row; i++)
  {
    for (int x = 0; x < row; x++)
    {
      if (arr[i] < arr[x])
      {
        int temp = arr[i];
        arr[i] = arr[x];
        arr[x] = temp;
      }
    }
  }
}

int main()
{
  int row;
  cout << "Write array size: ";
  cin >> row;

  int arr[row];

  cout << "Enter Array: " << endl;
  for (int i = 0; i < row; i++)
  {
    cout << "Element at " << i << ": ";
    cin >> arr[i];
  }

  cout << "Original Array: ";
  for (int i = 0; i < row; i++)
  {
    cout << " " << arr[i];
  }

  cout << endl;

  Sort(row, arr);

  cout << "Sorted Array: ";
  for (int i = 0; i < row; i++)
  {
    cout << " " << arr[i];
  }

  return 0;
}