#include <iostream>
using namespace std;

#define INF 99
#define MAX 10

void floydWarshall(int n, int D[MAX][MAX])
{
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
  int D[MAX][MAX];

  cout << "Enter the number of vertices: ";
  cin >> n;

  cout << "Enter the adjacency matrix (use 99 for no path):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> D[i][j];
    }
  }

  floydWarshall(n, D);

  return 0;
}