#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
  string name;
  double score;

public:
  Student(string nm, double s) : name(nm), score(s) {}

  virtual string getMajor() = 0;

  virtual string calculateGrade()
  {
    return "Grade not calculated";
  }

  void display()
  {
    cout << "Name : " << name << endl;
    cout << "Marks : " << score << endl;
  }
};

class EngineeringStudent : public Student
{
public:
  EngineeringStudent(string nm, double s) : Student(nm, s) {}

  string getMajor() override
  {
    return "Engineering";
  }

  string calculateGrade() override
  {
    if (score >= 90)
      return "O";
    else if (score >= 80)
      return "A+";
    else if (score >= 70)
      return "A";
    else if (score >= 60)
      return "B";
    else if (score >= 50)
      return "P";
    else
      return "F";
  }
};

class ArtsStudent : public Student
{
public:
  ArtsStudent(string nm, double s) : Student(nm, s) {}

  string getMajor() override
  {
    return "Arts";
  }

  string calculateGrade() override
  {
    if (score >= 90)
      return "O";
    else if (score >= 80)
      return "A+";
    else if (score >= 70)
      return "A";
    else if (score >= 60)
      return "B";
    else if (score >= 50)
      return "P";
    else
      return "F";
  }
};

int main()
{
  string engName, artName;
  double engScore, artScore;

  cout << "Enter name of Engineering Student: ";
  getline(cin, engName);
  cout << "Enter score of Engineering student: ";
  cin >> engScore;
  EngineeringStudent eng(engName, engScore);
  cout << endl;

  cin.ignore();
  cout << "Enter name of Arts Student: ";
  getline(cin, artName);
  cout << "Enter score for Arts student: ";
  cin >> artScore;
  ArtsStudent art(artName, artScore);

  cout << endl;

  eng.display();
  cout << "Major: " << eng.getMajor() << endl;
  cout << "Grade: " << eng.calculateGrade() << endl << endl;

  art.display();
  cout << "Major: " << art.getMajor() << endl;
  cout << "Grade: " << art.calculateGrade() << endl;

  return 0;
}