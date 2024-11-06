#include <iostream>
using namespace std;

int main()
{
  int num, rev = 0, rem, ori;
  cout << "Enter a number: ";
  cin >> num;
  ori = num;
  while (num != 0)
  {
    rem = num % 10;
    rev = rev * 10 + rem;
    num = num / 10;
  }
  if (ori == rev)
  {
    cout << ori << " is PALINDROME";
  }
  else
  {
    cout << ori << " is NOT PALINDROME";
  }

  return 0;
}