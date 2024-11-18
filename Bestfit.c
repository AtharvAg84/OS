#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

void displayMemoryStatus(int partitions[], int m, int allocation[], int n) {
    printf("\nMemory Status:\n");
    printf("Partition No.\tPartition Size\tRemaining Space\tAllocated Process\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t%d\t\t", i + 1, partitions[i], partitions[i]);
        
        // Find which process is allocated to this partition
        int allocated = -1;
        for (int j = 0; j < n; j++) {
            if (allocation[j] == i) {
                allocated = j;
                break;
            }
        }
        
        if (allocated != -1) {
            printf("Process %d\n", allocated + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

void bestFit(int partitions[], int m, int processes[], int n) {
    // Initialize allocation array
    int allocation[MAX_PROCESSES];  // Store allocated partition for each process

    // Initialize allocation array to -1 (not allocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Start allocation of processes
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        int minDifference = 99999; // A very large number to find the minimum difference

        // Search for the best fit partition for the process
        for (int j = 0; j < m; j++) {
            // If the partition is large enough and the space left after allocation is less than the current minimum difference
            if (partitions[j] >= processes[i] && partitions[j] - processes[i] < minDifference) {
                bestIdx = j;
                minDifference = partitions[j] - processes[i];
            }
        }

        // If a partition is found, allocate it
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            partitions[bestIdx] -= processes[i];  // Update partition size after allocation
        }
    }

    // Print the allocation results and memory status
    printf("\nProcess No.\tProcess Size\tPartition No.\tPartition Size Remaining\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i], allocation[i] + 1, partitions[allocation[i]]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processes[i]);
        }
    }

    // Display the final memory status
    displayMemoryStatus(partitions, m, allocation, n);
}

int main() {
    int m, n;

    // Input number of partitions
    printf("Enter number of partitions: ");
    scanf("%d", &m);

    // Input partition sizes
    int partitions[MAX_PARTITIONS];
    printf("Enter partition sizes:\n");
    for (int i = 0; i < m; i++) {
        printf("Partition %d size: ", i + 1);
        scanf("%d", &partitions[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process sizes
    int processes[MAX_PROCESSES];
    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Call the best fit algorithm
    bestFit(partitions, m, processes, n);

    return 0;
}
