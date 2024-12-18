#include <iostream>
using namespace std;

int lcs(char x[], char y[], int n, int m)
{
  int dp[n + 1][m + 1];

  for (int i = 0; i <= n; ++i)
  {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= m; ++j)
  {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      if (x[i-1] == y[j-1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }

  return dp[n][m];
}

int main()
{
  int n, m;

  cout << "Enter length of 1st sequence: ";
  cin >> n;
  cout << "Enter length of 2nd sequence: ";
  cin >> m;

  char x[n], y[m];

  cout << "Enter the first sequence: ";
  for (int i = 0; i < n; ++i)
  {
    cin >> x[i];
  }

  cout << "Enter the second sequence: ";
  for (int i = 0; i < m; ++i)
  {
    cin >> y[i];
  }

  int lcsLength = lcs(x, y, n, m);
  cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

  return 0;
}