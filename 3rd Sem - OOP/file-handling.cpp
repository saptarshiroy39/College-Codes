#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void WriteFile(string &fn)
{
  ofstream outf(fn);
  if (!outf)
  {
    cout << "Error !" << endl;
    return;
  }

  outf << "Rohit,36" << endl;
  outf << "Akash,19" << endl;
  outf.close();
}

void ReadFile(string &fn)
{
  ifstream inf(fn);
  if (!inf)
  {
    cout << "Error !" << endl;
    return;
  }

  string line;
  while (getline(inf, line))
  {
    cout << line << endl;
  }
  inf.close();
}

int main()
{
  string filename = "people.txt";
  WriteFile(filename);
  ReadFile(filename);

  return 0;
}