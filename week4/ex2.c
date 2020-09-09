#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// 8 processes for 3 loops, because in each iteration fork duplicates the amount of processes, 2^3 = 8
// 32 processes for 5 loops, same logic
void main(){
    for (int i = 0; i < 3; i++){
        fork();
        sleep(5);
    }
}