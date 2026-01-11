#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
  char data[100];
  int bits[100], codeword[100] = {0};

  cout << "\nEnter data: ";
  cin >> data;

  int len = strlen(data);

  // Calculate number of parity bits
  int r = 0;
  while (pow(2, r) < r + len + 1)
    r++;

  cout << "Parity bits (r): " << r << "\n";

  // Convert data to int array
  for (int i = 0; i < len; i++)
    bits[i] = data[i] - '0';

  // Mark parity positions with -1
  for (int i = 0; i < r; i++)
    codeword[int(pow(2, i))] = -1;

  // Fill data bits in reverse
  int j = 0;
  for (int i = len + r; i >= 1; i--)
  {
    if (codeword[i] != -1)
      codeword[i] = bits[j++];
  }

  // Calculate parity bits
  for (int i = 0; i < r; i++)
  {
    int pos = pow(2, i);
    int count = 0;
    for (int j = pos; j <= len + r; j++)
    {
      if (((j >> i) & 1) && codeword[j] != -1)
        count += codeword[j];
    }

    codeword[pos] = count % 2;
  }

  cout << "\nHamming codeword: ";
  for (int i = len + r; i >= 1; i--)
    cout << codeword[i] << " ";
  cout << "\n";

  return 0;
}