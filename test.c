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
	int pid, x;
	pid = getpid();

	struct sigaction old, new;
	new.sa_handler = fun;
	sigemptyset(&new.sa_mask);
	sigaddset(&new.sa_mask, 6);
	new.sa_flags = 0;

	x = sigaction(2, &new, &old);
	printf(1, "sigaction returned: %d\n", x);
	for(int i = 0; i < MASKLEN; i++)
		printf(1, "%d ", old.sa_mask.sigs[i]);
	printf(1, "\n");

	x = sigaction(2, &new, &old);
  printf(1, "sigaction returned: %d\n", x);
  for(int i = 0; i < MASKLEN; i++)
    printf(1, "%d ", old.sa_mask.sigs[i]);
	printf(1, "\n");

	kill(pid, 2);
	sleep(100);

	printf(1, "back in the main function...\n");
	exit();
}
