#include <iostream>
using namespace std;

class Appliance
{
public:
  virtual double getPowerConsumption() = 0;
};

class WashingMachine : public Appliance
{
private:
  double power;
  double hours;

public:
  WashingMachine(double p, double h) : power(p), hours(h) {}

  double getPowerConsumption() override
  {
    return (power * hours);
  }
};

class Refrigerator : public Appliance
{
private:
  double power;
  double hours;

public:
  Refrigerator(double p, double h) : power(p), hours(h) {}

  double getPowerConsumption() override
  {
    return (power * hours);
  }
};

int main()
{
  double wmPower, wmHours;
  double refPower, refHours;

  cout << "Power Rating of Washing Machine: ";
  cin >> wmPower;
  cout << "Usage Hour of Washing Machine: ";
  cin >> wmHours;

  cout << endl;

  cout << "Power Rating of Refrigerator: ";
  cin >> refPower;
  cout << "Usage Hour of Refrigerator: ";
  cin >> refHours;

  WashingMachine wm(wmPower, wmHours);
  Refrigerator fridge(refPower, refHours);

  cout << endl;

  cout << "Washing Machine Power Consumption: " << wm.getPowerConsumption() << " kWh/day" << endl;
  
  cout << "Refrigerator Power Consumption: " << fridge.getPowerConsumption() << " kWh/day" << endl;

  return 0;
}