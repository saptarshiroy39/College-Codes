#include <iostream>
using namespace std;

int findMax(int A[], int size)
{
  int k = A[0];
  for (int i = 0; i < size; i++)
  {
    if (A[i] > k)
    {
      k = A[i];
    }
  }
  return k;
}

void countingSort(int A[], int size, int div)
{
  int k = findMax(A, size);
  int B[size];
  int C[k + 1];

  for (int i = 0; i <= k; i++)
  {
    C[i] = 0;
  }

  for (int j = 0; j < size; j++)
  {
    C[(A[j] / div) % 10]++;
  }

  for (int i = 1; i <= k; i++)
  {
    C[i] = C[i] + C[i - 1];
  }

  for (int j = size - 1; j >= 0; j--)
  {
    B[C[(A[j] / div) % 10] - 1] = A[j];
    C[(A[j] / div) % 10]--;
  }

  for (int i = 0; i < size; i++)
  {
    A[i] = B[i];
  }
}

void radixSort(int A[], int size)
{
  int k = findMax(A, size);
  int d = 0;

  // Calculate d [d = no. of passes]
  while (k > 0)
  {
    k = k / 10;
    d++;
  }

  int div = 1;

  for (int i = 1; i <= d; i++)
  {
    countingSort(A, size, div);
    div *= 10;
  }
}

int main()
{
  int size;
  int div;
  cout << "Enter size of array: ";
  cin >> size;

  int A[size];
  cout << "Enter elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }

  cout << "Sorted Array: ";
  radixSort(A, size);

  for (int i = 0; i < size; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}