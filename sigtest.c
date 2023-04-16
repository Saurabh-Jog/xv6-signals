#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

void fun1(int s)
{
	printf(2, "Inside signal handler 1\n");
	return;
}

void fun2(int s)
{
  printf(2, "Inside signal handler 2\n");
  return;
}

void fun3(int s)
{
  printf(2, "Inside signal handler 3\n");
  return;
}

int main()
{
	/*struct sigaction s1;
	s1.sa_handler = fun;
	sigemptyset(&s1.sa_mask);
	sigaction(SIGINT, &s1, 0);

	kill(getpid(), SIGINT);
	printf(2, "going to sleep\n");
	sleep(100);
	printf(2, "Came back from sleep\n");
	exit();*/

	int pid = fork();
	if(pid == 0){
		printf(2, "I am the child\n");
		// struct sigaction s1;
		struct sigset mask;
		sigemptyset(&mask);
		sigaddset(&mask, SIGSTOP);
		sigprocmask(&mask, 0);
		// s1.sa_handler = fun1;
		signal(SIGCHLD, fun1);
		// s1.sa_handler = fun2;
    signal(SIGURG, fun2);
		// s1.sa_handler = fun3;
    signal(SIGINT, fun3);
		sleep(100);
		printf(2, "The child is back\n");
		exit();
	}
	sleep(10);
	kill(pid, SIGCHLD);
	kill(pid, SIGSTOP);
	kill(pid, SIGURG);
	kill(pid, SIGINT);
	wait();
	exit();

}
