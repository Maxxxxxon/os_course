#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 10
unsigned long int thread_id[NUM_THREADS];
void * printinf(int i) {
    printf("I am thread %d, created in iteration %d\n", (int) pthread_self(), i);
    pthread_exit(NULL);
}
int main(int argc, char * argv[]) {
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Creating the thread in iteration %d\n", i);
        int rc = pthread_create(&thread_id[i], NULL, printinf, i);
        if (rc) {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);    
        }
        pthread_join(thread_id[i], NULL);
        printf("Thread in iteration %d exited\n", i);
    }
    pthread_exit(NULL);
}