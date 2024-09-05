#include <iostream>
using namespace std;

void bubbleSort(int size, int array[])
{
  int swap;

  for (int i = 0; i < size - 1; i++)
  {
    swap = 0;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swap = 1;
      }
    }

    if (!swap)
    {
      break;
    }
  }
}

int main()
{
  int size;
  cout << "Enter the number of elements: ";
  cin >> size;

  int array[size];
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }

  cout << "Original array: ";
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  bubbleSort(size, array);

  cout << "Sorted array: ";
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}