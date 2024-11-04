#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
  int real, imag;

public:
  Complex(int r = 0, int i = 0) : real(r), imag(i) {}

  friend istream &operator>>(istream &in, Complex &c)
  {
    cout << "Enter Real part: ";
    in >> c.real;
    cout << "Enter Imaginary part: ";
    in >> c.imag;
    return in;
  }

  friend ostream &operator<<(ostream &out, Complex &c)
  {
    out << c.real;
    if (c.imag >= 0)
      out << " + " << c.imag << "i";
    else
      out << " - " << -c.imag << "i";
    return out;
  }

  bool operator==(Complex &obj)
  {
    return (real == obj.real) && (imag == obj.imag);
  }
};

int main()
{
  Complex C1, C2;

  cout << "Enter Complex Number 1 - " << endl;
  cin >> C1;
  cout << endl;
  cout << "Enter Complex Number 2 - " << endl;
  cin >> C2;
  cout << endl;

  cout << "Complex Number 1 -> " << C1 << endl;
  cout << "Complex Number 2 -> " << C2 << endl;
  cout << endl;

  if (C1 == C2)
    cout << "Both complex numbers are Equal.";

  else
    cout << "The complex numbers are Not Equal.";

  return 0;
}