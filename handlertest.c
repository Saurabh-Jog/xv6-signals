#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

int main()
{
  int pid;

  printf(2, "creating a new process...\n");
  pid = fork();
  if(pid == 0)
  {
    printf(2, "process with pid = %d running\n", getpid());
    while(1)
      ;
  }
  sleep(10);
  printf(2, "sending SIGCHLD to the process with pid = %d ...\n", pid);
  kill(pid, SIGCHLD);
  sleep(10);
  printf(2, "signal has been ignored by the default handler IGN\n");

  printf(2, "\nsending SIGKILL to the process with pid = %d ...\n", pid);
  sleep(10);
  kill(pid, SIGKILL);
  wait();
  printf(2, "process with pid = %d was killed by default signal handler TERM\n", pid);

  printf(2, "\ncreating a new process...\n");
  pid = fork();
  if(pid == 0)
  {
    printf(2, "process with pid = %d running\n", getpid());
    sleep(100);
    printf(2, "process with pid = %d running again\n", getpid());
    exit();
  }
  sleep(10);
  printf(2, "sending SIGSTOP to the process with pid = %d ...\n", pid);
  kill(pid, SIGSTOP);
  wait();
  printf(2, "process %d was stopped by default signal handler STOP\n", pid);

  sleep(10);
  printf(2, "\nsending SIGCONT to the stopped process with pid = %d\n", pid);
  kill(pid, SIGCONT);
  wait();

  printf(2, "\nHANDLER TEST PASSED :)\n");
  exit();
}
