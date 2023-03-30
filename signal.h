#define SIGTERM 0
#define SIGIGN 1
#define SIGCONT 2
#define SIGSTOP 3
#define SIGKILL 4

#define NSIGS   10 // number of signals

struct signal_struct {
	int is_pending;
	void (*sa_handler)(int);
	int sender_pid;
};

struct sigset {
	int sigs[NSIGS];
};

typedef struct sigset* sigset;

struct sigaction {
	void (*sa_handler)(int);
	sigset sa_mask;
  int sa_flags;
};
