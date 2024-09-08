#include <iostream>
using namespace std;

class Parent
{
public:
  virtual void sayHello()
  {
    cout << "Hello from Parent !" << endl;
  }
};

class Child : public Parent
{
public:
  void sayHello()
  {
    cout << "Hello from Child !" << endl;
  }
};

int main()
{
  Child c1;
  c1.sayHello();

  return 0;
}