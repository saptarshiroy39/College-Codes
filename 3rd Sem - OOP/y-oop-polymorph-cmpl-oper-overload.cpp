#include <iostream>
using namespace std;

class Complex
{
public:
  double real;
  double imag;

  Complex(double r, double i)
  {

    real = r;
    imag = i;
  }

  Complex operator+(Complex &obj)
  {
    return Complex(real + obj.real, imag + obj.imag);
  }

  Complex operator-(Complex &obj)
  {
    return Complex(real - obj.real, imag - obj.imag);
  }

  void Display()
  {
    cout << real;

    if (imag >= 0)
    {
      cout << " + " << imag << "i";
    }
    else
    {
      cout << " - " << -imag << "i";
    }
  }
};

int main()
{
  double r1, i1;
  double r2, i2;
  double r3, i3;

  cout << "Enter 1st Real & Imaginary Part: ";
  cin >> r1 >> i1;

  cout << "Enter 2nd Real & Imaginary Part: ";
  cin >> r2 >> i2;

  cout << "Enter 3rd Real & Imaginary Part: ";
  cin >> r3 >> i3;

  Complex c1(r1, i1);
  Complex c2(r2, i2);
  Complex c3(r3, i3);

  Complex c4 = c1 + c2 + c3;
  Complex c5 = c1 - c2 - c3;

  cout << "Addition result is : ";
  c4.Display();

  cout << endl;

  cout << "Subtraction result is : ";
  c5.Display();

  return 0;
}
