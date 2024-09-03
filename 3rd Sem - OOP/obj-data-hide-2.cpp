#include <iostream>
using namespace std;

class Teacher
{
private:
  long phone;
  float salary;

public:
  string name;
  string dept;
  string sub;
  int id;

  void setData();
  void getData();
};

void Teacher::setData()
{
  cout << "Name of Teacher: ";
  cin.ignore(); // Ignore leftover newline character in the buffer

  getline(cin, name);
  cout << "Department: ";
  getline(cin, dept);

  cout << "Subject: ";
  getline(cin, sub);

  cout << "ID: ";
  cin >> id;

  cout << "Phone No.: ";
  cin >> phone;

  cout << "Salary: ";
  cin >> salary;
}

void Teacher::getData()
{
  cout << endl;
  cout << "Name: " << name << endl;
  cout << "Department: " << dept << endl;
  cout << "Subject: " << sub << endl;
  cout << "ID: " << id << endl;
  cout << "Phone No.: " << phone << endl;
  cout << "Salary: " << salary << endl;
}

int main()
{
  Teacher t1;
  Teacher t2;

  t1.setData();
  t2.setData();

  t1.getData();
  t2.getData();

  return 0;
}