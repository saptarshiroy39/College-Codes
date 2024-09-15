#include <iostream>
using namespace std;

class Stack
{
private:
  int top;
  int item;
  int array[10];

public:
  Stack()
  {
    top = -1;
  }

  void getData()
  {
      cout << "Enter item to Push : ";
      cin >> item;
  }

  void push()
  {
    if (top >= 9)
    {
      cout << endl
           << "Stack Overflow !" << endl;
    }
    else
    {
      getData();
      top++;
      array[top] = item;
    }
  }

  void pop()
  {
    if (top < 0)
    {
      cout << endl
           << "Stack Underflow !" << endl;
    }
    else
    {
      cout << array[top] << " Popped from Stack." << endl;
      top--;
    }
  }

  void display()
  {
    if (top < 0)
    {
      cout << "Stack is Empty." << endl;
    }
    else
    {
      cout << endl
           << "Stack Elements: " << endl;
      for (int i = top; i >= 0; i--)
      {
        cout << array[i] << endl;
      }
      cout << endl;
    }
  }
};

int main()
{
  Stack s;
  int choice, element;
  while (1)
  {
    cout << endl;
    cout << "1. PUSH " << endl;
    cout << "2. POP" << endl;
    cout << "3. DISPLAY" << endl;
    cout << "4. EXIT" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      s.push();
      break;

    case 2:
      s.pop();
      break;

    case 3:
      s.display();
      break;
      
    case 4:
      cout << "Exiting..." << endl;
      return 0;

    default:
      cout << "Invalid choice !" << endl;
    }
  }

  return 0;
}