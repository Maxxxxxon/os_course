#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void main(){
    for (int i = 0; i < 30; i++){
        void* pointer = malloc(1024 * 1024 * 256);
        memset(pointer, 0, 1024 * 1024 * 256);
        sleep(1);
    }
}

// Comments for ex2
// free memory decreases over time if we run the program
// at the moment when we have too few free memory OS starts to use the swap area
// "so" becomes non-zero, and "swpd" increases


// Comments for ex3
// free memory decreases over time if we run the program
// the process raises to the top and stays on the second place right after Zoom
// at the moment when we have too few free memory OS starts to use the swap area,
// and used Swap increases
// after the process finishes both free Swap and free Mem increases, but there still
// leaves some used space in Swap