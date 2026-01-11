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

  // Non-Parameterized Constructor
  Banking()
  {
    cout << "Welcome to OOP BANK of VS Code" << endl;
  }

  // Parameterized Constructor
  Banking(double bal, string pass, string n, int a)
  {
    cout << "Enter Name: ";
    getline(cin, n);

    cout << "Enter A/C No.: ";
    cin >> a;

    cout << "Enter Current Balane: ";
    cin >> bal;

    cin.ignore();
    cout << "Enter Password: ";
    getline(cin, pass);

    cout << endl;

    balance = bal;
    password = pass;
    name = n;
    ac = a;
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
  double bal;
  string pass;
  string n;
  int a;

  Banking();
  Banking b1(bal, pass, n, a);
  b1.getInfo();

  return 0;
}