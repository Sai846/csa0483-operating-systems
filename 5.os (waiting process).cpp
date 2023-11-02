#include <stdio.h>
struct Process {
    int pid; 
    int bt;  
    int priority; 
    int wt;  
    int tat; 
};
void findWaitingTime(struct Process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].wt + proc[i - 1].bt;
    }
}
void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt;
}
void findAverageTime(struct Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }
    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turnaround time = %.2f\n", total_tat / n);
}
void sortProcessesByPriority(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].priority > proc[j + 1].priority) {
                // Swap processes
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &proc[i].priority);
        proc[i].pid = i + 1;
    }
    sortProcessesByPriority(proc, n);
    findAverageTime(proc, n);
    return 0;
}
