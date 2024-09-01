#include <iostream>
using namespace std;

class Student
{
private:
  string name; // attribute
  int roll;

  // function
  public:
  void setdata(string n, int r)
  {
    name = n;
    roll = r;
  }

  void getdata()
  {
    cout << "Name : " << name << endl;
    cout << "Roll : " << roll << endl;
    cout << endl;
  }
};

int main()
{
  Student s1;
  Student s2;
  s1.setdata("Ram", 1);
  s2.setdata("Shyam", 2);

  s1.getdata();
  s2.getdata();

  return 0;
}