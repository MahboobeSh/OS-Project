#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
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
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
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
sys_helloWorld(void){
  

  cprintf("\n ****hello world from system call ***\n");
  return 22;

}


int
sys_clone(void){
  void (*func)(void*);
  void *arg;
  void *stack;
  if(argptr(0, (char**)&func, sizeof(*func)) < 0)
     return -1;
  if(argptr(1, (char**)&arg, sizeof(*arg)) < 0)
     return -1;
  if(argptr(2, (char**)&stack, PGSIZE) < 0)
     return -1; 

  return clone(func, arg, stack);
}

int
sys_join(void){

  void **temp_stack;
  if(argptr(0, (char **)&temp_stack, sizeof(temp_stack)) < 0)
     return -1;
  return join(temp_stack);
}