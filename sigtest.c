#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

void fun(int s)
{
	printf(2, "Inside signal hnadler\n");
	return;
}

int main()
{
	struct sigaction s1;
	s1.sa_handler = fun;
	sigemptyset(&s1.sa_mask);
	sigaction(SIGINT, &s1, 0);

	kill(getpid(), SIGINT);
	printf(2, "going to sleep\n");
	sleep(100);
	printf(2, "Came back from sleep\n");
	exit();

/*	char buf[10];
	read(2, buf, 10);
	int pid = fork();
	if(pid == 0){
		printf(2, "I am the child, I am going to stop myself\n");
		kill(getpid(), SIGSTOP);
		sleep(100);
		printf(2, "The child is back\n");
		exit();
	}
	wait();
	exit();*/

}
