#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

void fun(int signum)
{
  printf(2, "signal caught! executing user-defined signal handler\n");
  return;
}

int main()
{
  int p[2];
  pipe(p);
  int pid = fork();
  if(pid == 0){
    close(p[0]);
    signal(SIGINT, fun);
    printf(2, "Process calling pause and going to sleep\n");
    char s[5] = "pass";
    s[4] = 0;
    write(p[1], s, 5);
    pause();
    printf(2, "Process back from sleep\n");
    printf(2, "\nPAUSETEST PASSED :)\n");
    exit();
  }
  close(p[1]);
  char s[5];
  read(p[1], s, 5);
  sleep(100);
  kill(pid, SIGINT);
  wait();
  exit();
}
