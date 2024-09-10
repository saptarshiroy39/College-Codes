#include <iostream>
using namespace std;

class Float
{
public:
  float operand;

  Float(float op)
  {
    operand = op;
  }

  Float operator+(Float &obj)
  {
    float new_operand = operand + obj.operand;

    return new_operand;
  }

  Float operator-(Float &obj)
  {
    float new_operand = operand - obj.operand;

    return new_operand;
  }

  Float operator*(Float &obj)
  {
    float new_operand = operand * obj.operand;

    return new_operand;
  }

  Float operator/(Float &obj)
  {
    float new_operand = operand / obj.operand;

    return new_operand;
  }

  void display()
  {
    cout << operand << endl;
  }
};

int main()
{
  float op1;
  float op2;

  cout << "Enter 2 Values : ";
  cin >> op1 >> op2;

  Float f1(op1);
  Float f2(op2);

  Float f3 = op1 + op2;
  Float f4 = op1 - op2;
  Float f5 = op1 * op2;
  Float f6 = op1 / op2;

  cout << "Addition : " << op1 << " + " << op2 << " = ";
  f3.display();

  cout << "Subtraction : " << op1 << " - " << op2 << " = ";
  f4.display();

  cout << "Multiplication : " << op1 << " * " << op2 << " = ";
  f5.display();

  cout << "Division : " << op1 << " / " << op2 << " = ";
  f6.display();

  return 0;
}