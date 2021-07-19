#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"


int arrsum = 0;
int arr[] = {1, 2, 3, 4, 5, 6}; // 1 + 2 + 3 + 4 + 5 + 6 = 21

void sum(void *x){
    arrsum += *((int *)x);
    //printf(1,"\n i am a thread \n");
    exit();
}

int main(){
    for(int i = 0; i < 6; i++){
        thread_create(&sum,(void *)&arr[i]);
        //
        //printf(1,"the %d result is arrsum= %d\n", i,arrsum);
    }
    for(int i = 0; i < 6; i++){
        thread_join();
    }
    printf(1,"the final result is arrsum= %d\n", arrsum);

    exit(); 
}
