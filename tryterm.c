#include "types.h"
#include "user.h"

int main()
{
	sig_term(0);
	printf(1, "I shouldnt get printed\n");

	exit();
}








