#include <stdio.h>
#include <limits.h>

void matrixChain(int p[], int n)
{
  int m[n][n];
  int s[n][n];

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
  
  printf("Minimum Cost of Multiplication: %d\n", m[1][n - 1]);
}

int main()
{
  int n;
  printf("Enter number of matrices: ");
  scanf("%d", &n);

  int p[n + 1];
  printf("Enter %d values of p-Array: ",n+1);

  for (int i = 0; i < n + 1; i++)
  {
    scanf("%d", &p[i]);
  }

  matrixChain(p, n + 1);

  return 0;
}