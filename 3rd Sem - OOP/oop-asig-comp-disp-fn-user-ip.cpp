#include <iostream>
using namespace std;

class Exam
{
public:
  string name;
  double marks[10];
  double total;
  int tmax[10];

  void assign(int &sub)
  {
    cout << "Name of Student: ";
    getline(cin, name);

    cout << "Total number of subjects: ";
    cin >> sub;

    cout << "Enter Full-Marks: ";
    for (int i = 0; i < sub; i++)
    {
      cin >> tmax[i];
    }

    cout << "Enter respective Marks: ";
    for (int i = 0; i < sub; i++)
    {
      cin >> marks[i];
    }
  }

  void compute(int sub, double &total, double &avg)
  {
    total = 0;
    avg = 0;
    double sumPercent = 0;

    for (int i = 0; i < sub; i++)
    {
      total += marks[i];
      sumPercent += (marks[i] / tmax[i]) * 100;
    }

    avg = sumPercent / sub;
  }

  void display(double total, double avg)
  {
    cout << endl;
    cin.ignore();
    cout << "Name: " << name << endl;
    cout << "Total Marks Obtained: " << total << endl;
    cout << "Average: " << avg << "%" << endl;
    cout << endl;
  }
};

int main()
{
  int sub;
  double total;
  double avg;

  Exam s1;
  Exam s2;

  s1.assign(sub);
  s1.compute(sub, total, avg);
  s1.display(total, avg);

  s2.assign(sub);
  s2.compute(sub, total, avg);
  s2.display(total, avg);

  return 0;
}