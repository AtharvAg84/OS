#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX 100
#define scan(n) scanf("%d", &n);

void sort_proc(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; i++)
        {
            if (arrivalT[i] > arrivalT[j])
            {

                int temp1 = arrivalT[i];
                arrivalT[i] = arrivalT[j];
                arrivalT[j] = temp1;

                int temp2 = burstT[i];
                burstT[i] = burstT[j];
                burstT[j] = temp2;

                int temp3 = process[i];
                process[i] = process[j];
                process[j] = temp3;
            }
        }
    }
}

void sortB(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; i++)
        {
            if (burstT[i] > burstT[j])
            {

                int temp1 = arrivalT[i];
                arrivalT[i] = arrivalT[j];
                arrivalT[j] = temp1;

                int temp2 = burstT[i];
                burstT[i] = burstT[j];
                burstT[j] = temp2;

                int temp3 = process[i];
                process[i] = process[j];
                process[j] = temp3;
            }
        }
    }
}

// Priority Bases Schedulling (Non Pr)

// Call this function in the sorting process function
void calculateFcfs(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n, int timeQ)
{

    int ct[MAX];
    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (arrivalT[i] >= currentTime)
        {
            currentTime = arrivalT[i];
        }
        currentTime += burstT[i];
        ct[i] = currentTime;
    }

    // calculate the avg waiting time
}

void SRTF(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n, int timeQ)
{
    int ct[MAX];
    int currentTime = 0;

    int completed = 0;
    int remainingBT[MAX];
    for (int i = 0; i < n; i++)
    {
        remainingBT[i] = burstT[i];
    }

    while (completed < n)
    {
        int minIndex = -1;
        int minVal = 9999;

        for (int i = 0; i < n; i++)
        {
            if (arrivalT[i] < currentTime && remainingBT[i] > 0)
            {
                if (remainingBT[i] < minIndex)
                {
                    minIndex = i;
                    minVal = remainingBT[i];
                }
            }
        }

        if (minIndex == -1)
        {
            currentTime++;
            continue;
        }
        //
        remainingBT[minIndex]--;

        if (remainingBT[minIndex] == 0)
        {
            completed++;
            ct[minIndex] = currentTime + 1;
        }
        currentTime++;
    }
}
// calthisProcessAfter Sort Of BurstTime
void SJT(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n, int timeQ)
{
    int ct[MAX];
    int currentTime = 0;

    int completed = 0;
    int remainingBT[MAX];
    for (int i = 0; i < n; i++)
    {
        remainingBT[i] = burstT[i];
    }

    while (completed < n)
    {
        int minIndex = -1;
        int minVal = 9999;
        for (int i = 0; i < n; i++)
        {
            if (arrivalT[i] <= currentTime && remainingBT[i] > 0)
            {
                if (remainingBT[i] < minVal)
                {
                    minVal = remainingBT[i];
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1)
        {
            currentTime += 1;
        }
        else
        {
            currentTime += remainingBT[minIndex];
            ct[minIndex] = currentTime;
            remainingBT[minIndex] = 0;
            completed++;
        }
    }
}
void calculateRR(int process[MAX], int burstT[MAX], int arrivalT[MAX], int n, int timeQ)
{

    int ct[MAX];

    int remainingBT[MAX];
    for (int i = 0; i < n; i++)
    {
        remainingBT[i] = burstT[i];
    }

    int completed = 0;
    int currentTime = 0;

    while (completed < n)
    {

        for (int i = 0; i < n; i++)
        {
            if (arrivalT[i] <= currentTime && remainingBT[i] > 0)
            {
                if (remainingBT[i] <= timeQ)
                {
                    currentTime += remainingBT[i];
                    ct[i] = currentTime;
                    remainingBT[i] = 0;
                    completed++;
                    printf(" P%d completed at ");
                }

                else
                {
                    currentTime += timeQ;
                    remainingBT[i] -= timeQ;
                }
            }
        }
    }
}

int main()
{
    int n;
    scan(n);

    int process[MAX];
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
    }

    int arrivalT[MAX];
    int burstT[MAX];

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst and arrival time for P%d : ", i + 1);
        scan(burstT[i]);
        scan(arrivalT[i]);
    }

    int tq;
    scan(tq);

    // For priority schedulling
    int priority[MAX];

    for (int i = 0; i < n; i++)
    {
        printf("Enter priority for P%d : ", i + 1);
        scan(priority[i]);
        // scan(arrivalT[i]);
    }
}