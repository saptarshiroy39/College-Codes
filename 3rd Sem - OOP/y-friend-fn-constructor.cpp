#include <iostream>
using namespace std;

class Mir;
class Gian
{
  int money;
  friend void Rishu(Gian, Mir);

public:
  Gian(int m)
  {
    cout << "Gian gave : $";
    cin >> m;
    money = m;
  }
};

class Mir
{
  int money;
  friend void Rishu(Gian, Mir);

public:
  Mir(int m)
  {
    cout << "Mir gave : $";
    cin >> m;
    money = m;
  }
};

void Rishu(Gian g1, Mir m1)
{
  cout << "Rishu Collected : $" << g1.money + m1.money << endl;
}

int main()
{

  int m;
  Gian g1(m);
  Mir m1(m);

  Rishu(g1, m1);

  return 0;
}
