#include "signal"

int sigemptyset(struct igset *set)
{
	if(!set)
		return -1;
	for(int i = 0; i < NSIGS; i++)
		set->sigs[i] = 0;
	return 0;
}

int sigfillset(struct sigset *set)
{
	if(!set)
		return -1;
	for(int i = 0; i < NSIGS; i++)
		set->sigs[i] = 1;
	return 0;
}

int sigaddset(struct sigset *set, int signum)
{
	if(!set || signum >= NSIGS)
		return -1;
	for(int i = 0; i < NSIGS; i++){
		if(i == signum){
			set->sigs[i] = 1;
			return 0;
		}
	}
}

int sigdelset(struct sigset *set, int signum)
{
	if(!set || signum >= NSIGS)
		return -1;
	for(int i = 0; i < NSIGS; i++){
		if(i == signum){
			set->sigs[i] = 0;
			return 0;
		}
	}
}
