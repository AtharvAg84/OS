#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

// Function to allocate memory using First Fit method
void firstFit(int partitions[], int partitionCount, int processes[], int processCount) {
    // Traverse each process to allocate memory
    for (int i = 0; i < processCount; i++) {
        int allocated = 0;  // Flag to check if the process has been allocated
        for (int j = 0; j < partitionCount; j++) {
            // If partition is large enough and is free (0 means free)
            if (partitions[j] >= processes[i]) {
                printf("Process %d of size %d allocated to Partition %d of size %d\n", 
                        i + 1, processes[i], j + 1, partitions[j]);
                // Mark this partition as occupied (set it to 0)
                partitions[j] = 0; // Partition is now occupied
                allocated = 1;
                break; // Stop looking for more partitions after allocation
            }
        }
        if (!allocated) {
            // If no partition was found for the process
            printf("Process %d of size %d could not be allocated\n", i + 1, processes[i]);
        }
    }
}

// Function to display the memory status (partitions and processes)
void displayMemoryStatus(int partitions[], int partitionCount, int processes[], int processCount) {
    printf("\nMemory Status:\n");
    printf("Partition No.\tSize\tOccupied\n");
    for (int i = 0; i < partitionCount; i++) {
        printf("%d\t\t%d\t%s\n", i + 1, partitions[i], partitions[i] == 0 ? "Yes" : "No");
    }

    printf("\nProcess No.\tSize\tAllocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t%s\n", i + 1, processes[i], processes[i] == 0 ? "Yes" : "No");
    }
}

int main() {
    int numPartitions, numProcesses;

    // Get number of partitions
    printf("Enter the number of partitions: ");
    scanf("%d", &numPartitions);

    // Get size of each partition
    int partitions[MAX_PARTITIONS];
    for (int i = 0; i < numPartitions; i++) {
        printf("Enter size of Partition %d: ", i + 1);
        scanf("%d", &partitions[i]);
    }

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Get size of each process
    int processes[MAX_PROCESSES];
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Allocate memory using First Fit method
    firstFit(partitions, numPartitions, processes, numProcesses);

    // Display the final memory status
    displayMemoryStatus(partitions, numPartitions, processes, numProcesses);

    return 0;
}
