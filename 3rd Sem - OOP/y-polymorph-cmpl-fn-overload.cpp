#include <iostream>
using namespace std;

class Math
{
public:
  void calc(int a, int b)
  {
    double c = a + b;
    cout << "Result (int, int): " << c << endl;
  }

  void calc(int a, int b, int c)
  {
    double d = a + b + c;
    cout << "Result (int, int, int): " << d << endl;
  }

  void calc(double a, double b, double c)
  {
    double d = a * b * c;
    cout << "Result (double, double, double): " << d << endl;
  }
};

int main()
{
  Math m1;

  // Input for the first function
  int x1, y1;
  cout << "Enter two integers for addition: ";
  cin >> x1 >> y1;
  m1.calc(x1, y1);

  // Input for the second function
  int x2, y2, z2;
  cout << "Enter three integers for addition: ";
  cin >> x2 >> y2 >> z2;
  m1.calc(x2, y2, z2);

  // Input for the third function
  double x3, y3, z3;
  cout << "Enter three doubles for multiplication: ";
  cin >> x3 >> y3 >> z3;
  m1.calc(x3, y3, z3);

  return 0;
}