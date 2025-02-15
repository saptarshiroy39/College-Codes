#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }

  while (i < n1)
  {
    arr[k++] = L[i++];
  }

  while (j < n2)
  {
    arr[k++] = R[j++];
  }
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main()
{
  int size;
  cout << "Write the length of array: ";
  cin >> size;

  int arr[size];
  cout << "Enter Elements: ";
  for (int i = 0; i < size; i++)
  {
    cout << i;
    cin >> arr[i];
  }

  mergeSort(arr, 0, size - 1);

  cout << endl;

  cout << "Sorted array is: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i];
  }

  return 0;
}