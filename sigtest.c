#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

int i = 0;

void fun(int s)
{
  printf(2, "Caught signal %d\n", i);
  if(i+1 == SIGKILL || i+1 == SIGSTOP)
    i = i + 2;
  else
    i++;
  return;
}

int main()
{
  int p[2];
  pipe(p);

  int pid = fork();

  if(pid == 0){
    close(p[0]);
    printf(2, "Child created with pid = %d\n", getpid());
    printf(2, "Setting signal handlers for all signals\n");
    for(int j = 0; j < NSIGS; j++)
      signal(j, fun);

    char s[5] = "pass";
    s[4] = '\0';
    write(p[1], s, 5);

    sleep(50);
    if(i == NSIGS)
      printf(2, "\nSIGTEST PASSED :)\n");
    else
      printf(2, "\nSIGTEST FAILED :(\n");
    close(1);
    exit();
  }

  close(1);
  char s[5];
  read(p[0], s, 5);
  for(int j = 0; j < NSIGS; j++){
    if(j == SIGKILL || j == SIGSTOP)
      continue;
    kill(pid, j);
  }
  wait();
  close(0);
  exit();
}
