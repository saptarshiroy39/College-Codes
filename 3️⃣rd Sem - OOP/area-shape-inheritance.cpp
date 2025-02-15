#include <iostream>
using namespace std;

class Shape
{
protected:
  double width;
  double height;

public:
  void set_width(double w)
  {
    width = w;
  }

  void set_height(double h)
  {
    height = h;
  }
};

class Rectangle : public Shape
{
public:
  double get_area()
  {
    return (width * height);
  }
};

int main()
{
  double w;
  double h;

  Rectangle r;

  cout << "Enter the width : ";
  cin >> w;
  cout << "Enter the height : ";
  cin >> h;

  r.set_width(w);
  r.set_height(h);

  cout << "Area : " << r.get_area();

  return 0;
}