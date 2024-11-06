#include <iostream>
using namespace std;

class Math
{
public:
  void calc(int a, int b)
  {
    double c = a + b;
    cout << c << endl;
  }

  void calc(int a, int b, int c)
  {
    double d = a + b + c;
    cout << d << endl;
  }

  void calc(double a, double b, double c)
  {
    double d = a * b * c;
    cout << d << endl;
  }
};

int main()
{
  Math m1;
  m1.calc(10, 20);
  m1.calc(12, 23, 34);
  m1.calc(47.53, 24.31, 56.67);
  
  return 0;
}
