#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b)
{
  return (a > b) ? a : b;
}

int main()
{
  int a, b;
  cout << "Enter two integers: ";
  cin >> a >> b;
  cout << "The maximum integer is: " << findMax(a, b) << endl;

  float c, d;
  cout << "Enter two floats: ";
  cin >> c >> d;
  cout << "The maximum float is: " << findMax(c, d) << endl;

  return 0;
}