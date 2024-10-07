#include <iostream>
using namespace std;

class Shape
{
protected:
  double height;
  double width;

public:
  void set_height(double h)
  {
    height = h;
  }

  void set_width(double w)
  {
    width = w;
  }
};

class Rectangle : public Shape
{
public:
  double get_area()
  {
    return (height * width);
  }
};

int main()
{
  double h;
  double w;

  Rectangle r;

  cout << "Enter the height : ";
  cin >> h;
  cout << "Enter the width : ";
  cin >> w;

  r.set_height(h);
  r.set_width(w);

  cout << "Area : " << r.get_area();

  return 0;
}