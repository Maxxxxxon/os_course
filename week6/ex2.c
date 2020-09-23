#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival;
    int burst;
    int exit_time;
    int process_num;
};

int comp_arrival(struct process* a, struct process* b){
    return - b->arrival + a->arrival;
}

int comp_burst(struct process* a, struct process* b){
    return - b->burst + a->burst;
}

int comp_initial_order(struct process* a, struct process* b){
    return - b->process_num + a->process_num;
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
        tmp.process_num = i;
        ps[i] = tmp;
    }
    qsort(ps, n, sizeof(struct process), comp_arrival);
    int leftsteps = 0;
    int leftprocess_pointer = 0;
    int process_pointer = 0;
    for (int i = ps[0].arrival; leftprocess_pointer < n; i++){
        while (process_pointer < n && ps[process_pointer].arrival <= i){
            process_pointer+=1;
        }
        qsort(ps + leftprocess_pointer, process_pointer - leftprocess_pointer, sizeof(struct process), comp_burst);
        if (leftsteps == 0){
            leftsteps = ps[leftprocess_pointer].burst;
            ps[leftprocess_pointer].exit_time = i + ps[leftprocess_pointer].burst;
            leftprocess_pointer += 1;
        }
        leftsteps = max(leftsteps - 1, 0);
    }
    int turnaroundsum = 0;
    qsort(ps, n, sizeof(struct process), comp_initial_order);
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