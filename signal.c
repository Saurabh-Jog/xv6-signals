#include "signal.h"

int sigemptyset(struct sigset *set)
{
  if(!set)
    return -1;
  for(int i = 0; i < MASKLEN; i++)
    set->sigs[i] = 0;
  return 0;
}

int sigfillset(struct sigset *set)
{
  if(!set)
    return -1;
  for(int i = 0; i < MASKLEN; i++)
    set->sigs[i] = 0xff;
  return 0;
}

int sigaddset(struct sigset *set, int signum)
{
  if(!set || signum >= NSIGS)
    return -1;
  int byte = signum / 8;
  int bit = signum % 8;
  char filter = 1;
  set->sigs[byte] |= (filter << bit);
  return 0;
}

int sigdelset(struct sigset *set, int signum)
{
  if(!set || signum >= NSIGS)
    return -1;
  int byte = signum / 8;
  int bit = signum % 8;
  char filter = 1;
  set->sigs[byte] &= ~(filter << bit);
  return 0;
}
