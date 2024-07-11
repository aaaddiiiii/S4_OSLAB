#include <stdio.h>
#include <stdlib.h>
void main()
{
    // input no of process and resources
    int no_resources, no_processes;
    printf("Enter the number the processes:");
    scanf("%d", &no_processes);
    printf("Enter the number of resources:");
    scanf("%d", &no_resources);

    // fucking declarations
    int allocation[no_processes][no_resources], max[no_processes][no_resources];
    int available[no_resources], need[no_processes][no_resources], finish[no_processes];
    int safe[no_processes], ind = 0;

    // enter available array
    printf("Enter the Available Array ");
    for (int i = 0; i < no_processes; i++)
    {
        scanf("%d", &available[i]);
    }

    // enter allocation matrix
    printf("Enter the allocation matrix:");
    for (int i = 0; i < no_processes; i++)
    {
        for (int j = 0; j < no_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // enter max demand matrix
    printf("Enter the max matrix:");
    for (int i = 0; i < no_processes; i++)
    {
        for (int j = 0; j < no_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // create need matrix
    for (int i = 0; i < no_processes; i++)
    {
        for (int j = 0; j < no_resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // print need matrix
    printf("NEED MATRIX:\n");
    for (int i = 0; i < no_processes; i++)
    {
        for (int j = 0; j < no_resources; j++)
        {
            printf("%d", need[i][j]);
        }
    }

    // set finished[everything]=0
    for (int i = 0; i < no_processes; i++)
        finish[i] = 0;

    // safety algorithm
    for (int i = 0; i < no_processes; i++)
    {
        int flag = 0;
        for (int j = 0; j < no_processes; j++)
        {
            if (finish[i] == 0)
            {
                for (int k = 0; k < no_resources; k++)
                {
                    if (need[j][k] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safe[ind++] = i;
                    for (int y = 0; y < no_resources; y++)
                    {
                        available[y] += allocation[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }
    if (ind == no_processes)
    {
        printf("SAFE SEQUENCE:\n");
        for (int i = 0; i < no_processes; i++)
        {
            printf("P%d", safe[i]);
        }
    }
    else
    {
        printf("Not safe!!");
    }
}
