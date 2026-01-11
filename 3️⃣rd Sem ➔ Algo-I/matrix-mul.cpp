#include <iostream>
using namespace std;

void matrixMul(int m, int n, int p, int q, int A[10][10], int B[10][10], int C[10][10])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < q; j++)
    {
      C[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void display(int m, int q, int C[10][10])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int m, n, p, q;

  cout << "Size of 1st Matrix: ";
  cin >> m >> n;

  int A[10][10];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "Element at [" << i << "][" << j << "]: ";
      cin >> A[i][j];
    }
  }

  cout << "Size of 2nd Matrix: ";
  cin >> p >> q;

  if (n != p)
  {
    cout << "Error! Columns of 1st Matrix must be equal to Rows of 2nd Matrix.";
    return -1;
  }

  int B[10][10];
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << "Element at [" << i << "][" << j << "]: ";
      cin >> B[i][j];
    }
  }

  cout << endl;

  int C[10][10];
  matrixMul(m, n, p, q, A, B, C);

  cout << "Product matrix: " << endl;
  display(m, q, C);

  return 0;
}