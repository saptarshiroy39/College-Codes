#include <iostream>
using namespace std;

int N;
int no_of_sol = 0;
int col[50];
int LD[50];
int RD[50];
int board[50];

void printBoard()
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (board[i] == j)
      {
        cout << board[i] << " ";
      }
      else
      {
        cout << ". ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void placeQueen(int i)
{
  for (int j = 1; j <= N; j++)
  {
    if (col[j] == 0 && LD[i - j + N] == 0 && RD[i + j - 1] == 0)
    {
      board[i] = j;
      col[j] = LD[i - j + N] = RD[i + j - 1] = 1;

      if (i == N)
      {
        printBoard();
        no_of_sol++;
      }
      else
      {
        placeQueen(i + 1);
      }

      board[i] = 0;
      col[j] = LD[i - j + N] = RD[i + j - 1] = 0;
    }
  }
}

int main()
{
  cout << "Enter size of the board (N): ";
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    col[i] = 0;
    if (i < 2 * N)
    {
      LD[i] = 0;
      RD[i] = 0;
    }
    board[i] = 0;
  }

  placeQueen(1);

  cout << "Total number of solutions: " << no_of_sol << endl;
  
  return 0;
}