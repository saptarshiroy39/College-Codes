#include <iostream>
#include <climits>
using namespace std;

void matrixChain(int p[], int n)
{
  int m[n][n];
  int s[n][n];
  // as row & col are same, this is allowed in cpp

  for (int i = 1; i < n; i++)
  {
    m[i][i] = 0;
  }

  for (int l = 2; l < n; l++)
  {
    for (int i = 1; i < n - l + 1; i++)
    {
      int j = i + l - 1;
      m[i][j] = INT_MAX;

      for (int k = i; k <= j - 1; k++)
      {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

        if (q < m[i][j])
        {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
  
  cout << "Minimum Cost of Multiplication: " << m[1][n - 1];
}

int main()
{
  int n;
  cout << "Enter number of matrices: ";
  cin >> n;

  int p[n + 1];
  cout << "Enter " << n+1 << " values of p-Array: ";

  for (int i = 0; i < n + 1; i++)
  {
    cin >> p[i];
  }

  matrixChain(p, n + 1);

  return 0;
}