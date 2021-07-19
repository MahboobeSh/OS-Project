#include "types.h"
#include "stat.h"
#include "user.h"


int x = 0;
int stack[4096];
void func(void* arg){
  int a = *(int*)arg;
  printf(1, "x + a = %d", x+a);
  return;
}

int main(int argc, char *argv[]) {
  
  // int tid = fork();
  int arg = 2;
  int tid = clone(&func,(void*)&arg,stack);
  printf(1, "tid is at %d\n", tid);
  


  exit();
}