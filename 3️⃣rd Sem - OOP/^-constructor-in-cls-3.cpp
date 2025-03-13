#include <iostream>
using namespace std;

class Banking
{
private:
  double balance;

protected:
  string password;

public:
  string name;
  int ac;

  // Parameterized Constructor
  Banking(double balance, string password, string name, int ac)
  {
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter A/C No.: ";
    cin >> ac;

    cout << "Enter Current Balane: ";
    cin >> balance;

    cin.ignore();
    cout << "Enter Password: ";
    getline(cin, password);

    cout << endl;

    this->balance = balance;
    this->password = password;
    this->name = name;
    this->ac = ac;
  }

  // Copy Constructor
  Banking(Banking &obj)
  {
    cout << "Copy Constructor..." << endl;

    this->balance = obj.balance;
    this->password = obj.password;
    this->name = obj.name;
    this->ac = obj.ac;
  }

  void getInfo()
  {
    cout << "A/C holder's Name: " << name << endl;
    cout << "A/C No: " << ac << endl;
    cout << "Current Balance: " << balance << endl;
    cout << "Password: " << password << endl;
    cout << endl;
  }
};

int main()
{
  double balance;
  string password;
  string name;
  int ac;

  Banking b1(balance, password, name, ac);
  b1.getInfo();

  Banking b2(b1);
  b2.getInfo();

  return 0;
}