/*
One needs 10 - 100 buffer fullfil iterations 
and less then 0.1 seconds to cause fatal race condition
*/
#include <pthread.h>
#include <stdio.h>

#define true 1
#define false 0

int buffer[100];
int c = 0;
int producer_sleep = false;
int consumer_sleep = true;

void producer_f(){
    for (int i = 0; true; i++){
        if (i % 10 == 0) {
            printf("%d\n", i);
        }
        while (producer_sleep)
            continue;
        if (c < 100){
            buffer[c] = 1;
            c++;
        }
        else{
            producer_sleep = 1;
            consumer_sleep = 0;
        }        
    }
}
void consumer_f(){
    for (int i = 1; true; i++){
        if (consumer_sleep)
            continue;
        
        if (c > 0){
            c--;
            buffer[c] = 0;
        }
        else{
            consumer_sleep = 1;
            producer_sleep = 0;
        }
    }
}

int main(int argc, char const *argv[]){
    pthread_t producer, consumer;
    printf("Producer started\n");
    pthread_create(&producer, NULL, producer_f, NULL);
    
    printf("Consumer started\n");
    pthread_create(&consumer, NULL, consumer_f, NULL);
}