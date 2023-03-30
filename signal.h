#define SIGTERM 0
#define SIGIGN 1
#define SIGCONT 2
#define SIGSTOP 3
#define SIGKILL 4

struct signal_struct {
	int is_pending;
	void (*sa_handler)(int);
	// void (*def_handler)(int);
	int sender_pid;
};
