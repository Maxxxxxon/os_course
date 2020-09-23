#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival;
    int burst;
    int leftburst;
    int exit_time;
    int process_num;
};

int comp_arrival(struct process* a, struct process* b){
    return - b->arrival + a->arrival;
}
int comp_initial_order(struct process* a, struct process* b){
    return - b->process_num + a->process_num;
}
int max(int a, int b){
    if (a > b)
        return a;
    return b;
}
int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int main()
{
    int n, quantum;
    scanf("%d", &n);
    scanf("%d", &quantum);
    struct process ps[n];
    for (int i = 0; i < n; i++){
        int arrival, burst;
        scanf("%d%d", &arrival, &burst);
        struct process tmp;
        tmp.arrival = arrival;
        tmp.burst = burst;
        tmp.leftburst = burst;
        tmp.exit_time = -1;
        tmp.process_num = i;
        ps[i] = tmp;
    }
    qsort(ps, n, sizeof(struct process), comp_arrival);
    int leftsteps = 0;
    int process_pointer = 0;
    for (int i = ps[0].arrival; 1; i++){
        int initial_pointer = process_pointer;
        int itsend = 0;
        while(ps[process_pointer].exit_time != -1){
            process_pointer += 1;
            process_pointer %= n;
            if (process_pointer == initial_pointer){
                itsend = 1;
                break;
            }
        }
        if (itsend)
            break;
        if (leftsteps == 0){
            leftsteps = min(quantum, ps[process_pointer].leftburst);
            if (leftsteps == ps[process_pointer].leftburst)
                ps[process_pointer].exit_time = i + ps[process_pointer].leftburst;
            ps[process_pointer].leftburst -= leftsteps;
            process_pointer += 1;
            process_pointer %= n;
            // if (process_pointer == n){
            //     int incomplete = 0;
            //     process_pointer = 0;
            //     for (int j = 0; j < n; j++){
            //         if (ps[j].exit_time == -1){
            //             incomplete += 1;
            //         }
            //     }
            //     if (incomplete == 0){
            //         break;
            //     }
            // }
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