#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "signal.h"

void fun(int signum)
{
	printf(2, "I am the signal handler\n");
	return;
}

int main()
{
	int pid = fork();
	if(pid == 0){
		signal(SIGINT, fun);
		printf(2, "child calling pause\n");
		pause();
		printf(2, "Back from pause\n");
		exit();
	}
	sleep(300);
	kill(pid, SIGINT);
	wait();
	exit();
}
