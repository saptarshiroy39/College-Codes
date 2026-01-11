#include <stdio.h>

void RR(int bt[], int n, int quantum)
{
  int wt[n], tat[n];
  int remaining_bt[n];

  for (int i = 0; i < n; i++)
  {
    remaining_bt[i] = bt[i];
  }

  int time = 0;
  while (1)
  {
    int done = 1;
    for (int i = 0; i < n; i++)
    {
      if (remaining_bt[i] > 0)
      {
        done = 0;
        if (remaining_bt[i] > quantum)
        {
          time += quantum;
          remaining_bt[i] -= quantum;
        }
        else
        {
          time += remaining_bt[i];
          tat[i] = time;
          wt[i] = tat[i] - bt[i];
          remaining_bt[i] = 0;
        }
      }
    }

    if (done == 1)
      break;
  }

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
  }
}

int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int bt[n];
  printf("Enter the burst times:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Process %d: ", i);
    scanf("%d", &bt[i]);
  }

  int quantum;
  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  RR(bt, n, quantum);

  return 0;
}