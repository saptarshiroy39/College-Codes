#include <stdio.h>

typedef struct job
{
  int id;
  int profit;
  int dead;
} job;

void jobSequence(job arr[], int n)
{
  int i;
  int max_deadline = 0;

  for (i = 0; i < n; i++)
  {
    if (arr[i].dead > max_deadline)
    {
      max_deadline = arr[i].dead;
    }
  }

  int sequence[max_deadline];

  for (i = 0; i < max_deadline; i++)
  {
    sequence[i] = -1;
  }

  for (i = 0; i < n; i++)
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

  printf("\nJob sequence to maximize profit: \n");
  for (i = 0; i < max_deadline; i++)
  {
    if (sequence[i] != -1)
    {
      printf(" job-%d ", sequence[i]);
    }
  }
}

void bubbleSort(job arr[], int r)
{
  job p;
  int i, j;
  for (i = 0; i < r - 1; i++)
  {
    for (j = 0; j < r - i - 1; j++)
    {
      if (arr[j].profit < arr[j + 1].profit)
      {
        p = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = p;
      }
    }
  }
}

int main()
{
  int m, i;

  printf("Enter number of jobs : ");
  scanf("%d", &m);
  job j[m];

  for (i = 0; i < m; i++)
  {
    j[i].id = i + 1;
    
    printf("\n");

    printf("Profit for job-%d : ", i + 1);
    scanf("%d", &j[i].profit);

    printf("Deadline for job-%d : ", i + 1);
    scanf("%d", &j[i].dead);
  }

  bubbleSort(j, m);
  jobSequence(j, m);

  return 0;
}