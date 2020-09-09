#include <stdio.h>
#include <string.h>
#include <sys/types.h>


// running the program 10 times we see that the pid increases from some number
// (specifically, 3902) to this number + 20 with the step 1
// it happens because every time we run the programm and fork the process we create
// a new process, which requires new id, and that way pid increases
void main(){
    int n = 0;
    int parentpid = (int)(getpid());
    fork();
    int pid = (int)getpid();
    if (pid == parentpid){
        printf("Hello from parent [%d - %d]\n", pid, n);
    }
    else{
        printf("Hello from child [%d - %d]\n", pid, n);
    }
}