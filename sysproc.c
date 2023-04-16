#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "signal.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid, signum;

  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &signum) < 0)
	return -1;
  return kill(pid, signum);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_sigaction(void)
{
  int signum;
	int a, oa;
  uint act_addr, oldact_addr;
  struct sigaction *act;
  struct sigaction *oldact;

  if(argint(0, &signum) < 0 || argint(1, &a) < 0 || argint(2, &oa) < 0)
	  return -1;
	act_addr = (uint)a;
	oldact_addr = (uint)oa;
  act = (struct sigaction*)act_addr;
  oldact = (struct sigaction*)oldact_addr;

  if(oldact) {
		getsigmask(&oldact->sa_mask);
		getsighandler(signum, &oldact->sa_handler);
  }
  if(act) {
		setsigmask(&act->sa_mask);
		setsighandler(signum, act->sa_handler);
  }
  return 0;
}

int
sys_sigprocmask(void)
{
	int a, oa;
  uint set_addr, oldset_addr;
  struct sigset *set;
  struct sigset *oldset;

  if(argint(0, &a) < 0 || argint(1, &oa) < 0)
    return -1;
  set_addr = (uint)a;
  oldset_addr = (uint)oa;
  set = (struct sigset*)set_addr;
  oldset = (struct sigset*)oldset_addr;

	if(oldset)
		getsigmask(oldset);
	if(set)
		setsigmask(set);
	return 0;
}

int
sys_signal(void)
{
  int signum;
	int a;
  uint sa_address;

	if(argint(0, &signum) < 0 || argint(1, &a) < 0)
	  return -1;

  sa_address = (uint)a;
	void(*sa_handler)(int) = (void(*)(int))sa_address;
  setsighandler(signum, sa_handler);
	return 0;
}

int
sys_pause(void)
{
  return pause();
}
