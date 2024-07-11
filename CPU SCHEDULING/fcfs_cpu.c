#include <stdio.h>

int main()
{
    int burstTime[20], waitingTime[20], turnaroundTime[20], arrivalTime[20];
    int completionTime[20], i, n;
    float avgwt, avgtat;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for Process %d -- ", i);
        scanf("%d", &arrivalTime[i]);

        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &burstTime[i]);
    }

    // Calculate completion, turnaround and waiting times
    completionTime[0] = arrivalTime[0] + burstTime[0];
    turnaroundTime[0] = completionTime[0] - arrivalTime[0];
    waitingTime[0] = turnaroundTime[0] - burstTime[0];

    avgwt = waitingTime[0];
    avgtat = turnaroundTime[0];

    for (i = 1; i < n; i++)
    {
        if (arrivalTime[i] > completionTime[i - 1])
        {
            completionTime[i] = arrivalTime[i] + burstTime[i];
        }
        else
        {
            completionTime[i] = completionTime[i - 1] + burstTime[i];
        }
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];

        avgwt += waitingTime[i];
        avgtat += turnaroundTime[i];
    }

    printf("\t PROCESS \tARRIVAL TIME \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", i, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nAverage Waiting Time - %f", avgwt);
    printf("\nAverage Turnaround Time - %f", avgtat);

    // Print Gantt chart
    printf("\n\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        if (i > 0 && arrivalTime[i] > completionTime[i - 1])
        {
            printf(" | IDLE ");
        }
        printf(" | P%d ", i);
    }
    printf("|\n");

    // Print time chart
    printf("0");
    for (i = 0; i < n; i++)
    {
        if (i > 0 && arrivalTime[i] > completionTime[i - 1])
        {
            printf("   %d", arrivalTime[i]);
        }
        printf("   %d", completionTime[i]);
    }
    printf("\n");

    return 0;
}