#include <stdio.h>

void FCFS(int bt[], int n)
{
  int wt[n];
  int tat[n];

  wt[0] = 0; // First process has no waiting time

  for (int i = 1; i < n; i++)
  {
    wt[i] = bt[i - 1] + wt[i - 1];
  }

  for (int i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i];
  }

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }
}

int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int bt[n];
  printf("Enter the burst times of the processes: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &bt[i]);
  }

  FCFS(bt, n);

  return 0;
}