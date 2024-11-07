#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> numbers;
  int n, value;
  cout << "Enter the no. of integers : ";
  cin >> n;

  cout << "Enter " << n << " integers : ";
  for (int i = 0; i < n; i++)
  {
    cin >> value;
    numbers.push_back(value);
  }

  sort(numbers.begin(), numbers.end());

  auto last = unique(numbers.begin(), numbers.end());
  numbers.erase(last, numbers.end());

  cout << "Sorted Unique : ";
  for (int num : numbers)
  {
    cout << num << " ";
  }

  return 0;
}