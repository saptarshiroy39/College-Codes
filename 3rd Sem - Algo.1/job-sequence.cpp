#include <iostream>
using namespace std;

struct Job
{
  int id;
  int profit;
  int dead;
};

void jobSequence(Job arr[], int n)
{
  int max_deadline = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i].dead > max_deadline)
    {
      max_deadline = arr[i].dead;
    }
  }

  int sequence[max_deadline];

  for (int i = 0; i < max_deadline; i++)
  {
    sequence[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    int j = arr[i].dead - 1;
    
    while (j >= 0)
    {
      if (sequence[j] == -1)
      {
        sequence[j] = arr[i].id;
        break;
      }
      j--;
    }
  }

  cout << "\nJob sequence to maximize profit: \n";
  for (int i = 0; i < max_deadline; i++)
  {
    if (sequence[i] != -1)
    {
      cout << " job-" << sequence[i] << " ";
    }
  }
  cout << endl;
}

void bubbleSort(Job arr[], int r)
{
  for (int i = 0; i < r - 1; i++)
  {
    for (int j = 0; j < r - i - 1; j++)
    {
      if (arr[j].profit < arr[j + 1].profit)
      {
        Job temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int m;
  cout << "Enter number of jobs: ";
  cin >> m;

  Job j[m];
  for (int i = 0; i < m; i++)
  {
    j[i].id = i + 1;

    cout << "\nProfit for job-" << i + 1 << ": ";
    cin >> j[i].profit;

    cout << "Deadline for job-" << i + 1 << ": ";
    cin >> j[i].dead;
  }

  bubbleSort(j, m);
  jobSequence(j, m);

  return 0;
}
