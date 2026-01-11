#include <iostream>
using namespace std;

int main()
{
  char choice;
  int n;
  int count = 0;

  cout << "Enter 'e' for even or 'o' for odd parity: ";
  cin >> choice;

  cout << "Enter number of bits: ";
  cin >> n;

  int a[n];
  cout << "Enter " << n << " bit data: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 1)
      count++;
  }

  cout << "\nOriginal: ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  int parity = (choice == 'e') ? count % 2 : 1 - count % 2;

  cout << "\nEncoded (" << (choice == 'e' ? "even" : "odd") << "): ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  cout << parity << "\n";

  return 0;
}