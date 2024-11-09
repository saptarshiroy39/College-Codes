#include <stdio.h>

void matrixMul(int m, int n, int p, int q, int A[m][n], int B[p][q], int C[m][q])
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

void display(int m, int q, int C[m][q])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < q; j++)
    {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int m, n, p, q;

  printf("Size of 1st Matrix: ");
  scanf("%d%d", &m, &n);
  int A[m][n];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Element at [%d][%d] : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  printf("\n");

  printf("Size of 2nd Matrix: ");
  scanf("%d%d", &p, &q);

  if (n != p)
  {
    printf("Error! Columns of 1st Matrix must be equal to Rows of 2nd Matrix.\n");
    return -1;
  }

  int B[p][q];
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      printf("Element at [%d][%d] : ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  printf("\n");

  int C[m][q];
  matrixMul(m, n, p, q, A, B, C);
  printf("Product matrix: \n");
  display(m, q, C);

  return 0;
}