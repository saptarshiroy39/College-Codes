#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cout << "Enter number of bits: ";
  cin >> n;

  int code[n];
  cout << "Enter Hamming code: ";
  for (int i = 0; i < n; i++)
    cin >> code[i];

  cout << "\nReceived: ";
  for (int i = 0; i < n; i++)
    cout << code[i] << " ";

  int r = 0;
  int error = 0;
  while (pow(2, r) < n)
  {
    r++;
  }

  for (int i = 0; i < r; i++)
  {
    int pos = pow(2, i);
    int count = 0;

    for (int j = pos; j <= n; j++)
    {
      if ((j & pos) && code[n - j] == 1)
        count++;
    }
    if (count % 2)
      error += pos;
  }

  if (error)
  {
    cout << "\nError at position: " << error;
    code[n - error] = 1 - code[n - error];
    cout << "\nCorrected: ";
    for (int i = 0; i < n; i++)
      cout << code[i] << " ";
  }
  else
  {
    cout << "\nNo error detected.";
  }
  cout << "\n";

  return 0;
}