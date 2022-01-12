/*
Program: Shortest Job First Scheduling algorithm
Language: C
*/

#include <stdio.h>
#include <stdlib.h>

struct PCB{
    int pid, burst, wait, turnaround;
}p[10], temp;

void pline(int x){
    for(int i=0; i<x; i++){
        printf("-");
    }
    printf("\n");
}

int main()
{
    int i, num, j, sum=0, w_total=0, t_total=0;
    float w_avg=0.0, t_avg=0.0;

    printf("Enter the number of process: ");
    scanf("%d", &num);

    for(i=0; i<num; i++){
        p[i].pid = i+1;
        printf("Enter the burst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // sort the array in order of their burst time
    for(i=0; i<num-1; i++){
        for(j=0; j<num-i-1; j++){
            if(p[j].burst > p[j+1].burst){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // finding the wait and turnaround time
    for(i=0; i<num; i++){
        sum += p[i].burst;
        p[i].turnaround = sum;
        p[i].wait = p[i].turnaround - p[i].burst;
    }
    pline(44);
    printf("PID\tBurst\tWait\tTurnaround\n");
    pline(44);
    for(i=0; i<num; i++){
        printf("%d\t%d\t%d\t%d\n", p[i].pid,p[i].burst, p[i].wait, p[i].turnaround);
        w_total += p[i].wait;
        t_total += p[i].turnaround;
    }
    pline(44);
    t_avg = t_total/(float)num;
    w_avg = w_total/(float)num;
    printf("\nTotal Turnaround time: %d.", t_total);
    printf("\nAverage Turnaround time: %.3f.", t_avg);

    printf("\nTotal Waiting time: %d.", w_total);
    printf("\nAverage Waiting time: %.3f.", w_avg);

    return 0;
}
