#include <iostream>
#include <cctype> // for using isalpha fn.
#include <string>
using namespace std;

class Company
{
public:
  string s;

  int isvalid(string s)
  {
    if (s.length() >= 3 && s.length() <= 100)
    {
      for (char c : s)
      {
        if (!isalpha(c)) // isalpha fn. is a standard library fn. used to check whether a character is an alphabetic letter (uppercase or lowercase).
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
    if (username.length() < 3 || username.length() > 100)
    {
      cout << "✕ INVALID" << endl;

      if (username.length() < 3)
      {
        cout << "Too Short!" << endl;
      }

      else if (username.length() > 100)
      {
        cout << "Too Long!" << endl;
      }

      cout << "Username has " << username.length() << " characters." << endl;
      cout << "Username must have characters between 3 & 100." << endl;
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
    cout << endl
         << "Enter Username " << i + 1 << ": ";
    cin >> v.username;
    v.validateUsername(v.username);
  }
  
  return 0;
}