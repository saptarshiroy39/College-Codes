#include <iostream>
using namespace std;

void Increment(int A[], int k)
{
  int i = 0;
  while (i < k && A[i] == 1)
  {
    A[i] = 0;
    i++;
  }
  if (i < k)
  {
    A[i] = 1;
  }
}

void PrintBinary(int A[], int k)
{
  for (int i = k - 1; i >= 0; --i)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main()
{
  int k;
  cout << "Enter the number of bits: ";
  cin >> k;

  int A[k] = {0};
  int n;
  cout << "Enter the number of increments: ";
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    Increment(A, k);
    PrintBinary(A, k);
  }

  return 0;
}