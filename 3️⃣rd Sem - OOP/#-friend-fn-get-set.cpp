#include <iostream>
using namespace std;

class Mir;
class Gian
{
  int money;
  friend void Rishu(Gian, Mir);

public:
  void setMoney()
  {
    cout << "Gian gave : $";
    cin >> money;
  }
};

class Mir
{
  int money;
  friend void Rishu(Gian, Mir);

public:
  void setMoney()
  {
    cout << "Mir gave : $";
    cin >> money;
  }
};

void Rishu(Gian g1, Mir m1)
{
  cout << "Rishu Collected : $" << g1.money + m1.money << endl;
}

int main()
{
  Gian g1;
  Mir m1;

  g1.setMoney();
  m1.setMoney();

  Rishu(g1, m1);

  return 0;
}