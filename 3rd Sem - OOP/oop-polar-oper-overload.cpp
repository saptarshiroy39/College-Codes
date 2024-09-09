#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
public:
  double radius;
  double angle;

  Polar(double r, double a)
  {
    radius = r;
    angle = a;
  }

  Polar operator+(Polar &other)
  {
    // Convert polar coordinates to Cartesian coordinates
    double x1 = radius * cos(angle);
    double y1 = radius * sin(angle);

    double x2 = other.radius * cos(other.angle);
    double y2 = other.radius * sin(other.angle);

    // Add Cartesian coordinates
    double x = x1 + x2;
    double y = y1 + y2;

    // Convert back to polar coordinates
    double new_radius = sqrt(x * x + y * y);
    double new_angle = atan2(y, x);

    return Polar(new_radius, new_angle);
  }

  void display()
  {
    cout << endl;
    cout << "After Addition : " << "(" << radius << "," << angle << ")" << endl;
  }
};

int main()
{
  double r1, a1;
  double r2, a2;

  cout << "For 1st Polar Point" << endl;
  cout << "Enter Radius : ";
  cin >> r1;
  cout << "Enter Angle (in radian) : ";
  cin >> a1;

  cout << endl;

  cout << "For 2nd Polar Point" << endl;
  cout << "Enter Radius : ";
  cin >> r2;
  cout << "Enter Angle (in radian) : ";
  cin >> a2;

  Polar p1(r1, a1);
  Polar p2(r2, a2);

  Polar p3 = p1 + p2;

  p3.display();

  return 0;
}