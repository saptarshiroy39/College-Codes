#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  int count = 0;
  char choice;

  cout << "Enter 'e' for even parity or 'o' for odd parity: ";
  cin >> choice;

  cout << "Enter the number of bits: ";
  cin >> n;

  vector<int> a(n);
  cout << "Enter " << n << " bit binary data: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cout << "\nOriginal data: ";
  for (int bit : a)
  {
    cout << bit;
    if (bit == 1)
      count++;
  }

  int parityBit;
  if (choice == 'e')
  {
    parityBit = (count % 2 == 0) ? 0 : 1;
    cout << "\nEncoded data using even parity: ";
  }
  else if (choice == 'o')
  {
    parityBit = (count % 2 == 0) ? 1 : 0;
    cout << "\nEncoded data using odd parity: ";
  }
  else
  {
    cout << "\nInvalid choice!";
    return 0;
  }

  // Print encoded data
  for (int bit : a)
    cout << bit;
  cout << parityBit << endl;

  return 0;
}