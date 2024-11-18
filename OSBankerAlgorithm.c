#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define scan(n) scanf("%d", &n)

void calculateNeed(int need[MAX][MAX], int n, int m, int allocate[][10], int maxneed[][10])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxneed[i][j] - allocate[i][j];
        }
    }
}

bool isSafe(int n, int m, int avail[], int allocate[][10], int maxneed[][10])
{
    int need[10][10];
    bool finish[10] = {false};
    int safeSeq[10], count = 0;
    int work[10];

    calculateNeed(need, n, m, allocate, maxneed);

    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    while (count < n)
    {
        bool found = false;
        for (int p = 0; p < n; p++)
        {
            if (!finish[p])
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[p][j] > work[j]) break;
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocate[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) return false;
    }
    printf("System is in a safe state. Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

int main()
{
    int n, m; // n - process, m - resources
    scan(n);
    scan(m);

    int avail[m];
    int maxneed[n][m];
    int allocated[n][m];

    // Enter the current Available resources.
    printf("Enter the resources Available: ");
    for (int i = 0; i < m; i++) {
        scan(avail[i]);
    }

    printf("Enter the max_need and allocated resources for each process:\n");
    for (int i = 0; i < n; i++) {
            
            printf("Max_Need for Process %d: ", i + 1);
            for (int j = 0; j < m; j++) { scan(maxneed[i][j]); }
            

            printf("Allocated for Process %d: ", i + 1);
            for (int j = 0; j < m; j++) { scan(allocated[i][j]); }

    }

    if (isSafe(n, m, avail, allocated, maxneed)) {
        printf("System is in a safe state.\n");
    } else {
        printf("System is not in a safe state.\n");
    }

    return 0;
}
