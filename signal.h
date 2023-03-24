#define NSIGS 10

struct signal_struct {
	int is_pending;
	void (*sa_handler)(int);
	void (*def_handler)(int);
	int sender_pid;
};
