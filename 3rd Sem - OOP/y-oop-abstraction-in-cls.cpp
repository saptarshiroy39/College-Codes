#include <iostream>
using namespace std;

class Teacher
{
private:
  long phone;

protected:
  double salary;

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

  double getSalary()
  {
    return salary;
  }

  void getInfo()
  {
    cout << endl;

    cout << "Name: " << name << endl;
    cout << "Department: " << dept << endl;
    cout << "Subject: " << sub << endl;
    cout << "ID: " << id << endl;

    cout << "Phone No.: " << getPhone() << endl;
    cout << "Salary: " << getSalary() << endl;
  }

  void setInfo()
  {
    cout << "Enter Name of Teacher: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, dept);

    cout << "Enter Subject: ";
    getline(cin, sub);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Phone No.: ";
    cin >> phone;

    cout << "Enter Salary: ";
    cin >> salary;

    setData(phone, salary);
  }
};

int main()
{
  Teacher t1;

  t1.setInfo();
  t1.getInfo();

  return 0;
}