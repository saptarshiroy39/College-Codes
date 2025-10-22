#include <iostream>
#include <cmath>
using namespace std;

void detectError(int code[], int n)
{
  int parity_count = 0;

  while (pow(2, parity_count) < n)
    parity_count++;

  int error_pos = 0;

  for (int i = 0; i < parity_count; i++)
  {
    int parity_pos = pow(2, i);
    int count = 0;

    for (int j = parity_pos; j <= n; j++)
    {
      if (j & parity_pos)
      {
        if (code[n - j] == 1)
          count++;
      }
    }

    if (count % 2 != 0)
      error_pos += parity_pos;
  }

  if (error_pos == 0)
  {
    cout << "\nNo error detected in the received code." << endl;
  }
  else
  {
    cout << "\nError detected at bit position (from right): " << error_pos << endl;
    code[n - error_pos] = (code[n - error_pos] == 0) ? 1 : 0;

    cout << "Corrected Code: ";
    for (int i = 0; i < n; i++)
    {
      cout << code[i];
    }

    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter the number of bits in received codeword: ";
  cin >> n;

  int code[n];
  cout << "Enter the received Hamming code bits (space-separated): ";
  for (int i = 0; i < n; i++)
  {
    cin >> code[i];
  }

  cout << "\nReceived Code: ";

  for (int i = 0; i < n; i++)
  {
    cout << code[i];
  }

  detectError(code, n);

  return 0;
}