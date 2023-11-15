#include <stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
void initialize();
void displayState();
int requestResources(int process, int request[]);
void releaseResources(int process, int release[]);
int main() {
    initialize();
    int request1[MAX_RESOURCES] = {2, 1, 0};
    if (requestResources(1, request1)) {
        printf("Resources allocated successfully.\n");
        displayState();
    } else {
        printf("Request denied. System is in an unsafe state.\n");
    }
    int release3[MAX_RESOURCES] = {0, 1, 0};
    releaseResources(3, release3);
    printf("Resources released.\n");
    displayState();
    return 0;
}
void initialize() {
    available[0] = 3;
    available[1] = 1;
    available[2] = 2;
    maximum[0][0] = 7; maximum[0][1] = 5; maximum[0][2] = 3;
    maximum[1][0] = 3; maximum[1][1] = 2; maximum[1][2] = 2;
    maximum[2][0] = 9; maximum[2][1] = 0; maximum[2][2] = 2;
    maximum[3][0] = 2; maximum[3][1] = 2; maximum[3][2] = 2;
    maximum[4][0] = 4; maximum[4][1] = 3; maximum[4][2] = 3;

    // Initialize allocation and need matrices
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            allocation[i][j] = 0;
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

void displayState() {
    printf("Available resources: %d %d %d\n", available[0], available[1], available[2]);
    printf("   Process   |   Maximum   |   Allocation   |   Need   \n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("      P%d      |     %d %d %d     |       %d %d %d       |     %d %d %d\n",
               i, maximum[i][0], maximum[i][1], maximum[i][2],
               allocation[i][0], allocation[i][1], allocation[i][2],
               need[i][0], need[i][1], need[i][2]);
    }
}
int requestResources(int process, int request[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > need[process][i]) {
            printf("Request denied. Process %d's request exceeds its need.\n", process);
            return 0;  
        }
    }
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > available[i]) {
            printf("Request denied. Insufficient resources available.\n");
            return 0; 
        }
    }
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
    return 1;  
}
void releaseResources(int process, int release[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available[i] += release[i];
        allocation[process][i] -= release[i];
        need[process][i] += release[i];
    }
}



