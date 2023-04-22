#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

int
main(int argc, char **argv)
{
  // int i;

  if(argc < 3){
    printf(2, "usage: send signal to pid...\n");
    exit();
  }
  kill(atoi(argv[1]), atoi(argv[2]));
  exit();
}
