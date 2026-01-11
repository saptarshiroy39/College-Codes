#include <iostream>
using namespace std;

class Vehicle
{
public:
  virtual double fuelEfficiency() = 0;
};

class Car : public Vehicle
{
private:
  double milesDriven;
  double gallonsUsed;

public:
  Car(double m, double g) : milesDriven(m), gallonsUsed(g) {}
  double fuelEfficiency() override
  {
    return milesDriven / gallonsUsed;
  }
};

class Bike : public Vehicle
{
private:
  double milesDriven;
  double gallonsUsed;

public:
  Bike(double m, double g) : milesDriven(m), gallonsUsed(g) {}

  double fuelEfficiency() override
  {
    return milesDriven / gallonsUsed;
  }
};

int main()
{
  double carMiles, carGallons;
  double bikeMiles, bikeGallons;

  cout << "Enter MILES driven by the Car: ";
  cin >> carMiles;
  cout << "Enter GALLONS used by the Car: ";
  cin >> carGallons;
  cout << endl;

  cout << "Enter MILES driven by the Bike: ";
  cin >> bikeMiles;
  cout << "Enter GALLONS used by the Bike: ";
  cin >> bikeGallons;
  cout << endl;

  Car c(carMiles, carGallons);
  Bike b(bikeMiles, bikeGallons);

  cout << "Fuel efficiency of the Car: " << c.fuelEfficiency() << " mpg" << endl;
  cout << "Fuel efficiency of the Bike: " << b.fuelEfficiency() << " mpg" << endl;

  return 0;
}