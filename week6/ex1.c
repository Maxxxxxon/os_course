/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival;
    int burst;
    int exit_time;
};

int comp(struct process* a, struct process* b){
    return - b->arrival + a->arrival;
}

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}
int main()
{
    int n;
    scanf("%d", &n);
    struct process ps[n];
    for (int i = 0; i < n; i++){
        int arrival, burst;
        scanf("%d%d", &arrival, &burst);
        struct process tmp;
        tmp.arrival = arrival;
        tmp.burst = burst;
        ps[i] = tmp;
    }
    qsort(ps, n, sizeof(struct process), comp);
    int leftsteps = 0;
    int process_pointer = 0;
    for (int i = ps[0].arrival; !(process_pointer == n && leftsteps == 0); i++){
        if (leftsteps == 0 && ps[process_pointer].arrival <= i){
            leftsteps = ps[process_pointer].burst;
            ps[process_pointer].exit_time = i + ps[process_pointer].burst;
            process_pointer += 1;
        }
        leftsteps = max(leftsteps - 1, 0);
    }
    int turnaroundsum = 0;
    printf("\nCorresponding processes' turn around time\n");
    for (int i = 0; i < n; i++){
        int turnaround = ps[i].exit_time - ps[i].arrival;
        turnaroundsum += turnaround;
        printf("%d ", turnaround);
    }
    printf("\nAverage turn around time: %f", turnaroundsum * 1.0 / n);
    
    int waitingsum = 0;
    printf("\nCorresponding processes' waiting time\n");
    for (int i = 0; i < n; i++){
        int waiting = ps[i].exit_time - ps[i].arrival - ps[i].burst;
        waitingsum += waiting;
        printf("%d ", waiting);
    }
    printf("\nAverage waiting time: %f", waitingsum * 1.0 / n);

    int end = 0;
    for (int i = 0; i < n; i++){
        end = max(end, ps[i].exit_time);
    }
    printf("\nCompletion time: %d\n", end);
}