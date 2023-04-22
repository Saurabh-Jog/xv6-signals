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
  printf(2, "This should not get executed %d\n", i);
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
    printf(2, "new peocess created with pid = %d\n", getpid());
    printf(2, "Setting signal mask and masking SIGINT\n");
    struct sigset set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(&set, 0);

    char s[5] = "pass";
    s[4] = '\0';
    write(p[1], s, 5);

    sleep(50);
    if(i == 0){
      printf(2, "signal is masked, handler is not evoked\n");
      printf(2, "\nSIGMASKTEST PASSED :)\n");
    }
    else
      printf(2, "\nSIGMASKTEST FAILED :(\n");
    close(1);
    exit();
  }

  close(1);
  char s[5];
  read(p[0], s, 5);
  printf(2, "Sending SIGINT to the process\n");
  kill(pid, SIGINT);
  wait();
  close(0);
  exit();
}
