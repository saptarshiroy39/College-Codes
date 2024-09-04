#include <iostream>
using namespace std;

class Animal
{
public:
  int age;
  string breed;
};

int main()
{
  Animal dog_1;
  dog_1.age = 3;
  dog_1.breed = "Husky";

  Animal dog_2;
  dog_2.age = 5;
  dog_2.breed = "G.Shephard";

  cout << "Dog 1" << endl;
  cout << "Age : " << dog_1.age << endl;
  cout << "Breed : " << dog_1.breed << endl;

  cout << endl;

  cout << "Dog 2" << endl;
  cout << "Age : " << dog_2.age << endl;
  cout << "Breed : " << dog_2.breed << endl;

  return 0;
}