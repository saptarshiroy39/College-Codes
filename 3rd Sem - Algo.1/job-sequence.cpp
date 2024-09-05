#include <iostream>
using namespace std;

void jobSequence(int job[], int profit[], int deadline[], int job_count)
{
  int max_deadline = 0;
  for (int i = 0; i < job_count; i++)
  {
    if (deadline[i] > max_deadline)
    {
      max_deadline = deadline[i];
    }
  }

  int sequence[max_deadline];
  for (int i = 0; i <= max_deadline; i++)
  {
    sequence[i] = -1;
  }

  for (int i = 0; i < job_count; i++)
  {
    int j = deadline[i];
    while (j >= 1)
    {
      if (sequence[j] == -1)
      {
        sequence[j] = job[i];
        break;
      }
      j--;
    }
  }

  cout << endl
       << "Job sequence for Maximum Profit: " << endl;
       
  for (int i = 1; i <= max_deadline; i++)
  {
    if (sequence[i] != -1)
    {
      cout << " Job-" << sequence[i] << ",";
    }
  }
}

void bubbleSort(int job[], int profit[], int deadline[], int job_count)
{
  int pf, jb, dl;

  for (int i = 0; i < job_count - 1; i++)
  {
    for (int j = 0; j < job_count - i - 1; j++)
    {
      if (profit[j] < profit[j + 1])
      {
        pf = profit[j];
        profit[j] = profit[j + 1];
        profit[j + 1] = pf;

        jb = job[j];
        job[j] = job[j + 1];
        job[j + 1] = jb;

        dl = deadline[j];
        deadline[j] = deadline[j + 1];
        deadline[j + 1] = dl;
      }
    }
  }
}

int main()
{
  int job_count;
  cout << "Enter number of Jobs : ";
  cin >> job_count;

  int job[job_count];
  int profit[job_count];
  int deadline[job_count];

  for (int i = 0; i < job_count; i++)
  {
    cout << endl;

    job[i] = i + 1;

    cout << "Job-" << i + 1 << endl;

    cout << "Profit : ";
    cin >> profit[i];

    cout << "Deadline : ";
    cin >> deadline[i];
  }

  bubbleSort(job, profit, deadline, job_count);
  jobSequence(job, profit, deadline, job_count);

  return 0;
}