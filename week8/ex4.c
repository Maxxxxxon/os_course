#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    for (int i = 0; i < 10; i++){
        void* pointer = malloc(1024 * 1024 * 10);
        memset(pointer, 0, 1024 * 1024 * 10);
        struct rusage data;
        getrusage(RUSAGE_SELF, &data);
        printf("%d\n", data.ru_maxrss);
        sleep(1);        
    }
}