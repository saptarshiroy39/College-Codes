#include <stdio.h>

void SJF(int bt[], int p[], int n)
{
  int wt[n], tat[n];

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (bt[i] > bt[j])
      {
        int temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        int t = p[i];
        p[i] = p[j];
        p[j] = t;
      }
    }
  }

  wt[0] = 0;

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
    printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }
}

int main()
{
  int n;
  printf("Enter number of jobs :");
  scanf("%d", &n);

  int p[n];
  int bt[n];
  printf("Enter Burst Times :");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &bt[i]);
    p[i] = i + 1;
  }

  SJF(bt, p, n);

  return 0;
}