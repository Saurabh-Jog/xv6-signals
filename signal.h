#define NSIGS   37 // number of signals
#define MASKLEN ((NSIGS % 8 == 0) ? (NSIGS/8) : NSIGS/8 + 1)

struct signal_struct {
	int is_pending;
	void (*sa_handler)(int);
	int sender_pid;
};

struct sigset {
	char sigs[MASKLEN];
};

struct sigaction {
	void (*sa_handler)(int);
	struct sigset sa_mask;
  int sa_flags;
};

#define SIGHUP 0
#define SIGINT 1
#define SIGQUIT 2
#define SIGILL 3
#define SIGTRAP 4
#define SIGABRT 5
#define SIGIOT 6
#define SIGBUS 7
#define SIGEMT 8
#define SIGFPE 9
#define SIGKILL 10
#define SIGUSR1 11
#define SIGSEGV 12
#define SIGUSR2 13
#define SIGPIPE 14
#define SIGALRM 15
#define SIGTERM 16
#define SIGSTKFLT 17
#define SIGCHLD 18
#define SIGCONT 19
#define SIGSTOP 20
#define SIGTSTP 21
#define SIGTTIN 22
#define SIGTTOU 23
#define SIGURG 24
#define SIGXCPU 25
#define SIGXFSZ 26
#define SIGVTALRM 27
#define SIGPROF 28
#define SIGWINCH 29
#define SIGIO 30
#define SIGPOLL 31
#define SIGPWR 32
#define SIGINFO 33
#define SIGLOST 34
#define SIGSYS 35
#define SIGUNUSED 36
