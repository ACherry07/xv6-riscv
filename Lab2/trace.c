#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 3){ //need at least 3 commmand line arguments
    fprintf(2, "Usage: trace mask command [args...]\n"); //writes to file descriptor 2, the stderr
    exit(1); //status code of exit is 1 -> failure
  }

  int mask = atoi(argv[1]); //convert the second command line argument from ascii to integer

  if(trace(mask) < 0){
    fprintf(2, "trace: failed to set mask\n"); 
    exit(1);
  }

  exec(argv[2], &argv[2]); //argv[2] is the command to run
                           //&argv[2] is the pointer to the command and its arguments

  
  // exec() only returns (-1) on error else it moves from the current process
  //fprintf(2, "trace: exec %s failed\n", argv[2]);

  exit(1);
}
