#include <stdio.h>
#define MEMORY_SIZE 1000
struct MemoryBlock {
    int id;      
    int size;     
    int allocated;
};
void initializeMemory(struct MemoryBlock memory[], int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        memory[i].id = -1;
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}
void displayMemory(struct MemoryBlock memory[], int numBlocks) {
    printf("Memory State:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("[%d] Size: %d, Allocated: %s\n", i, memory[i].size,
               memory[i].allocated ? "Yes" : "No");
    }
    printf("\n");
}
void worstFit(struct MemoryBlock memory[], int numBlocks, int processId, int processSize) {
    int largestBlockIndex = -1;
    int largestBlockSize = -1;
    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (largestBlockIndex == -1 || memory[i].size > largestBlockSize) {
                largestBlockIndex = i;
                largestBlockSize = memory[i].size;
            }
        }
    }
    if (largestBlockIndex != -1) {
        memory[largestBlockIndex].id = processId;
        memory[largestBlockIndex].allocated = 1;
        printf("Process %d allocated to block %d\n", processId, largestBlockIndex);
    } else {
        printf("Process %d cannot be allocated\n", processId);
    }
}
void deallocateMemory(struct MemoryBlock memory[], int numBlocks, int processId) {
    for (int i = 0; i < numBlocks; i++) {
        if (memory[i].id == processId) {
            memory[i].id = -1;
            memory[i].allocated = 0;
            printf("Memory block %d deallocated\n", i);
            return;
        }
    }
    printf("Process %d not found in memory\n", processId);
}
int main() {
    int numBlocks = 5;
    struct MemoryBlock memory[MEMORY_SIZE];
    initializeMemory(memory, numBlocks);
    displayMemory(memory, numBlocks);
    worstFit(memory, numBlocks, 1, 200);
    worstFit(memory, numBlocks, 2, 300);
    worstFit(memory, numBlocks, 3, 150);
    worstFit(memory, numBlocks, 4, 400);
    displayMemory(memory, numBlocks);
    deallocateMemory(memory, numBlocks, 2);
    displayMemory(memory, numBlocks);

    return 0;
}

