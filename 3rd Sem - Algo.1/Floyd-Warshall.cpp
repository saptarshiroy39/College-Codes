#include <iostream>
using namespace std;

#define INF 99

void floydWarshall(int n, int W[10][10])
{
  int D[10][10];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      D[i][j] = W[i][j];
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (D[i][k] + D[k][j] < D[i][j])
        {
          D[i][j] = D[i][k] + D[k][j];
        }
      }
    }
  }

  cout << "Shortest distances between every pair of vertices:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (D[i][j] == INF)
        cout << "INF ";
      else
        cout << D[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;
  int W[10][10];

  cout << "Enter the number of vertices: ";
  cin >> n;

  cout << "Enter the adjacency matrix (use 99999 for no path):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> W[i][j];
    }
  }

  floydWarshall(n, W);

  return 0;
}