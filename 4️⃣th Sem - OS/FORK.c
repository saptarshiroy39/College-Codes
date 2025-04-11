#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <number>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);

  pid_t pid = fork();

  if (pid == -1)
  {
    // Error in forking
    perror("Fork failed");
    return 1;
  }
  else if (pid == 0)
  {
    // Child process
    printf("Child process: Received number = %d\n", num);
  }
  else
  {
    // Parent process
    printf("Parent process: Received number = %d\n", num);
  }

  return 0;
}