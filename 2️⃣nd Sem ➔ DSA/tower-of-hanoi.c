#include <stdio.h>

int move_count = 0;

void towerofHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
  if (n == 1)
  {
    printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
    move_count++;
    return;
  }

  towerofHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
  move_count++;
  towerofHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  towerofHanoi(num_disks, 'A', 'C', 'B');
  printf("Total number of moves: %d\n", move_count);
  
  return 0;
}