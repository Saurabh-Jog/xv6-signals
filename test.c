#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

void fun()
{
	printf(1, "\nI am the signal handler... yayyy :)\n");
	return;
}

int main()
{
	int pid;
	pid = getpid();
	struct sigaction s;
	s.sa_handler = fun;
	sigemptyset(&s.sa_mask);
	sigaction(SIGSTOP, &s, 0);
	// printf(2, "my pid is %d and i am going to stop myself...qwa.", pid);
	printf(2, "Sending signal to myslef\n");
	kill(pid, SIGSTOP);
	sleep(100);
	printf(2, "back from signal handler\n");
	// printf(2, "back in the main function...\n");
	exit();
}
