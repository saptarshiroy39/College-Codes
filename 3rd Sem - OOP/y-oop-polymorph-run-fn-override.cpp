#include <iostream>
using namespace std;

class Parent
{
public:
  void getMessage()
  {
    cout << "Parent Class..." << endl;
  }
};

class Child : public Parent
{
public:
  void getMessage()
  {
    cout << "Child Class..." << endl;
  }
};

int main()
{
  Parent p1;
  p1.getMessage();

  Child c1;
  c1.getMessage();

  return 0;
}