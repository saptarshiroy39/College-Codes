#include <iostream>
using namespace std;

int main()
{
  int a = 0, b = 1, c, i, num;
  cout << "Enter the number of elements: ";
  cin >> num;
  cout << "Fibonacci series of" << num << "elements: " << endl;
  cout << a << " " << b;
  for (i = 2; i < num; ++i)
  {
    c = a + b;
    a = b;
    b = c;
    cout << " " << c;
  }
  return 0;
}