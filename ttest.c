#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"



int x =0;

void tfunc(void* arg){
  int a = *(int*)arg;
  x = x+a;
  printf(3, "x is at %d in thread n \n", x);
  return;
}



int main(int argc, char *argv[]) {
	void *stack;
	
	stack = (void*)malloc(4096);
	
  
  int arg = 3;
  printf(1, "x is at in main process before thread clone %d\n", x);
  int tid = clone(&tfunc, &arg,stack);
  printf(1, "tid is at %p\n", tid);
  sleep(20);
  printf(1, "x is at in main process %d\n", x);




  exit();
}

