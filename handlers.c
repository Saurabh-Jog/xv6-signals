#include "types.h"
#include "user.h"

void sig_term(int signo)
{
	exit();
}

void sig_ign(int signo)
{
	return;
}

void sig_stop(int signo)
{
	return;
}

void sig_cont(int signo)
{
	return;
}
