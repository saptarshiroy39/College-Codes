#include <iostream>
using namespace std;

int knapsack(int n, int m, int weights[], int profits[])
{
  int v[n + 1][m + 1];

  for (int i = 0; i <= n; i++)
  {
    v[i][0] = 0;
  }
  for (int j = 0; j <= m; j++)
  {
    v[0][j] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (weights[i - 1] > j)
      {
        v[i][j] = v[i - 1][j];
      }
      else
      {
        v[i][j] = max(v[i - 1][j], v[i - 1][j - weights[i - 1]] + profits[i - 1]);
      }
    }
  }

  return v[n][m];
}

int main()
{
  int n, m;

  cout << "Enter the number of items: ";
  cin >> n;
  cout << "Enter the capacity of knapsack: ";
  cin >> m;

  int weights[n], profits[n];

  cout << "Enter weights of items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }

  cout << "Enter profits of items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> profits[i];
  }

  int maxProfit = knapsack(n, m, weights, profits);
  cout << "Maximum profit: " << maxProfit << endl;

  return 0;
}