#include <iostream>
#include <string>
using namespace std;

class Company
{
public:
  string s;
  int isvalid(string s)
  {
    if (s.length() > 3 && s.length() <= 100)
    {
      for (char c : s)
      {
        if (!isalpha(c))
        {
          cout << "✕ INVALID" << endl;
          return -1;
        }
      }
      cout << "✓ VALID" << endl;
    }
  }
};

class Validator : public Company
{
public:
  string username;
  void validateUsername(const string &username)
  {
    if (username.length() <= 3)
    {
      cout << "Too short: " << username.length() << endl;
      cout << "✕ INVALID" << endl;
    }
    else
    {
      isvalid(username);
    }
  }
};

int main()
{
  int test;

  do
  {
    cout << "Enter number of TEST CASES (1-1000): ";
    cin >> test;

    if (test < 1 || test > 1000)
    {
      cout << "Invalid number of TEST CASES !" << endl;
    }

  } while (test < 1 || test > 1000);

  Validator v;

  for (int i = 0; i < test; i++)
  {
    string username;
    cout << endl <<"Enter Username " << i + 1 << ": ";
    cin >> v.username;
    v.validateUsername(v.username);
  }
  return 0;
}