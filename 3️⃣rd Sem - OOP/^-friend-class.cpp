#include <iostream>
using namespace std;

class Rectangle;

class AreaCalculator
{
public:
  void calculateArea(Rectangle rect);
};

class Rectangle
{
private:
  double length;
  double width;
 
public:
  Rectangle(double l, double w)
  {
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;

    length = l;
    width = w;
  }

  void displayDimensions()
  {
    cout << "Length: " << length << ", Width: " << width << endl;
  }
  
  friend class AreaCalculator;

};

void AreaCalculator::calculateArea(Rectangle r)
{
  double area = r.length * r.width;
  cout << "Area of the Rectangle: " << area << endl;
}

int main()
{
  double l, w;

  Rectangle r1(l, w);

  r1.displayDimensions();

  AreaCalculator calculator;

  calculator.calculateArea(r1);

  return 0;
}