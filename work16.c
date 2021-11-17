#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

int main() {

  printf("may the forking commence\n");

  printf("fork 1 --> cp1 (child process 1)\n");
  int cp1 = fork();

  int cp2;
  if (cp1) {

    printf("fork 2 --> cp2 (child process 2)\n");
    cp2 = fork();

  }

  // child process
  if (!cp1 || !cp2)  {

    printf("===========================================\n");
    printf("child process\n");

    printf("child pid: %d\n", getpid());

    srand(time(NULL));
    int sleeptime = (rand() % 4) + 2;
    sleep(sleeptime);

    printf("sleeptime (%d seconds) is over\n", sleeptime);
    printf("===========================================\n");

    return sleeptime;

  }

  // parent process
  else {

    printf("===========================================\n");
    printf("parent process\n");

    int status;
    int child_pid = wait(&status);
    int sleeptime = WEXITSTATUS(status);

    printf("child pid: %d\tsleeptime: %d\n", child_pid, sleeptime);

    printf("parent is done\n");
    printf("===========================================\n");

    printf("fin\n");
    printf("===========================================\n");

    return 0;

  }

  return 0;

}
