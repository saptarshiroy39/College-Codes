#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  string dob;
};

class Teacher
{
public:
  double salary;
};

class Student : public Person
{
public:
  int roll;
};

class Research : public Teacher, public Student
{
public:
  string res;

  void setInfo()
  {
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter DOB: ";
    getline(cin, dob);

    cout << "Enter Roll No.: ";
    cin >> roll;

    cin.ignore();
    
    cout << "Enter Research Area: ";
    getline(cin, res);

    cout << "Enter Salary: ";
    cin >> salary;
  }

  void getInfo()
  {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "DOB: " << dob << endl;
    cout << "Roll No.: " << roll << endl;
    cout << "Department: " << res << endl;
    cout << "Salary: " << salary << endl;
  }
};

int main()
{
  Research r1;
  r1.setInfo();
  r1.getInfo();

  return 0;
}