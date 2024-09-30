#include <iostream>
using namespace std;

class Shape
{
protected:
  int height;
  int width;

public:
  void set_height(int h)
  {
    height = h;
  }

  void set_width(int w)
  {
    width = w;
  }
};

class Rectangle : public Shape
{
public:
  int get_area()
  {
    return (height * width);
  }
};

int main()
{
  int h, w;

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