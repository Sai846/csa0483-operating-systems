#include <stdio.h>

struct Process {
    int pid; // Process ID
    int bt;  // Burst time
    int wt;  // Waiting time
    int tat; // Turnaround time
    int rt;  // Remaining time
};

void findWaitingTime(struct Process proc[], int n, int quantum) {
    int remaining_bt[n];
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = proc[i].bt;
        proc[i].wt = 0;
    }

    int t = 0; // Current time

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0; // There is a pending process

                if (remaining_bt[i] > quantum) {
                    t += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    t = t + remaining_bt[i];
                    proc[i].wt = t - proc[i].bt;
                    remaining_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt;
}

void findAverageTime(struct Process proc[], int n, int quantum) {
    findWaitingTime(proc, n, quantum);
    findTurnAroundTime(proc, n);

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turnaround time = %.2f\n", total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i + 1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findAverageTime(proc, n, quantum);

    return 0;
}
