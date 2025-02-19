#include <stdio.h>

int main()
{
  int n;
  int i, sum = 0;
  int *ptr;
  printf("Enter the size of array : ");
  scanf("%d", &n);

  int array[n];
  printf(" Enter array elements :");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
  }

  ptr = array;

  for (i = 0; i < n; i++)
  {
    sum = sum + *ptr;
    ptr++;
  }
  printf("The Sum is: %d", sum);

  return 0;
}

/*
#include <stdio.h>

int main()
{
  int n;
  int i, mul = 1;
  int *ptr;
  printf("Enter the size of array : ");
  scanf("%d", &n);

  int array[n];
  printf(" Enter array elements :");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
  }
    
  ptr = array;

  for (i = 0; i < n; i++)
  {
    mul = mul * *ptr;
    ptr++;
  }
  printf("The Product is: %d", mul);
  
  return 0;
}
*/