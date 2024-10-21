#include <iostream>
using namespace std;

class Counter
{
private:
  static int count;

public:
  Counter()
  {
    count++;
  }
  static int getCount()
  {
    return count;
  }
  void showCount()
  {
    cout << "Currrent Count : " << count << endl;
  }
};

int Counter::count = 0;

int main()
{
  Counter obj1;
  Counter obj2;
  Counter obj3;

  cout << "Number of objects created: " << Counter::getCount() << endl;
  
  obj1.showCount();
  obj2.showCount();
  obj3.showCount();

  return 0;
}