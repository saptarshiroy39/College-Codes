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

  void setData(long ph, float sal)
  {
    phone = ph;
    salary = sal;
  }

  long getPhone()
  {
    return phone;
  }

  float getSalary()
  {
    return salary;
  }
};

int main()
{
  Teacher t1;

  cout << "Name of Teacher: ";
  getline(cin, t1.name);

  cout << "Department: ";
  getline(cin, t1.dept);

  cout << "Subject: ";
  getline(cin, t1.sub);

  int id;
  cout << "ID: ";
  cin >> t1.id;

  long phone;
  cout << "Phone No.: ";
  cin >> phone;

  float salary;
  cout << "Salary: ";
  cin >> salary;

  t1.setData(phone, salary);

  cout << endl;

  cout << "Name: " << t1.name << endl;
  cout << "Department: " << t1.dept << endl;
  cout << "Subject: " << t1.sub << endl;
  cout << "ID: " << t1.id << endl;

  cout << "Phone No.: " << t1.getPhone() << endl;
  cout << "Name: " << t1.getSalary() << endl;

  return 0;
}