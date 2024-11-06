#include <iostream>
using namespace std;

int isPrime(int num)
{
  if (num <= 1)
  {
    return false;
  }

  if (num <= 3)
  {
    return true;
  }

  if (num % 2 == 0 || num % 3 == 0)
  {
    return false;
  }

  for (int i = 5; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int start, end;
  cout << "Enter the starting and ending numbers: ";
  cin >> start >> end;

  cout << "Prime numbers between " << start << " and " << end << " are: ";
  for (int i = start; i <= end; i++)
  {
    if (isPrime(i))
    {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}