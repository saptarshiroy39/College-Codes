#include <iostream>
using namespace std;

class Number
{
public:
  int value;

  void setdata()
  {
    cout << "Enter value : ";
    cin >> value;
  }

  int getdata()
  {
    return value;
  }
};

int sum(Number n1, Number n2)
{
  int sum;
  sum = n1.getdata() + n2.getdata();
  return sum;
}

int main()
{

  int a;
  Number n1;
  Number n2;

  n1.setdata();
  n2.setdata();

  n1.getdata();
  n2.getdata();

  a = sum(n1, n2);
  cout << "Sum = " << a;
  return 0;
}