#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"


int thread_create(void(*func)(void*), void* arg){

	void *stack = (void*)malloc(4096*2);

	int pid = clone(func, arg, stack);
	
	return pid;
}
int thread_join(void){

  void *thread_stack;

	int pid = join(&thread_stack);
	if (pid != -1){
		free(thread_stack);
		//printf(1,"stack thread %d is freed\n",pid);
	}
  return pid;

}
